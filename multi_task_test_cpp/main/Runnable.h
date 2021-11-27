#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>
#include "sdkconfig.h"
#include <math.h>
#include <stdio.h>
#include <string>

namespace mia {
    namespace rtos {

        #define INFINITE 0xffffffff

        class Mutex {
            private:
        
            SemaphoreHandle_t mutex;

            public:

            /**
             * @brief Construct a new Mutex object
             * 
             */
            Mutex() {
                mutex = xSemaphoreCreateMutex();
            }

            /**
             * @brief Destroy the Mutex object
             * 
             */
            virtual ~Mutex() {
                vSemaphoreDelete(mutex);
            }

            /**
             * @brief Take mutex.
             * 
             * @param timeout_msec Timeout in milliseconds. 
             * @return true Operation success.
             * @return false Operation failed.
             */
            bool Wait(time_t timeout_msec = INFINITE) {
                TickType_t timeout_ticks;
                if (timeout_msec == INFINITE) {
                    timeout_ticks = portMAX_DELAY;
                }else{
                    timeout_ticks = timeout_msec/portTICK_PERIOD_MS;
                }
                return xSemaphoreTake(mutex, timeout_ticks);
            }

            /**
             * @brief Release mutex.
             * 
             * @return true Operation success.
             * @return false Operation failed.
             */
            bool Release() {
                return xSemaphoreGive(mutex);
            }
        };

        class Event {
            private:

            SemaphoreHandle_t event;

            public:

            /**
             * @brief Construct a new Event object
             * 
             */
            Event() {
                vSemaphoreCreateBinary(event);
            }

            /**
             * @brief Destroy the Event object
             * 
             */
            virtual ~Event() {
                vSemaphoreDelete(event);
            }

            /**
             * @brief Signal event.
             * 
             * @return true Event signaled.
             * @return false Error signaling event.
             */
            bool Signal() {
                return xSemaphoreGive(event);
            }

            /**
             * @brief Wait event with timeout.
             * 
             * @param timeout_msec Timeout.
             * @return true Event signaled.
             * @return false Event not signaled and timeout reached.
             */
            bool Wait(time_t timeout_msec = INFINITE) {
                TickType_t timeout_ticks;
                if (timeout_msec == INFINITE) {
                    timeout_ticks = portMAX_DELAY;
                }else{
                    timeout_ticks = timeout_msec/portTICK_PERIOD_MS;
                }
                return xSemaphoreTake(event, timeout_ticks);
            }

            /**
             * @brief Reset event.
             * 
             */
            void Reset() {
                while (Wait(0)) {}
            }
        };

        class AutoMutexLock {
            private:

                Mutex* mutex = NULL;
            public:

                /**
                 * @brief Construct a new Auto Mutex Lock object
                 * 
                 * @param m Mutex to take during Automutex live.
                 */
                AutoMutexLock(Mutex* m) {
                    this->mutex = m;
                    mutex->Wait();
                }

                /**
                 * @brief Destroy the Auto Mutex Lock object and release mutex.
                 * 
                 */
                virtual ~AutoMutexLock() {
                    mutex->Release();
                }
        };

        /**
         * @brief Base class for creating tasks in C++. 
         * 
         * Create child classes and implement Run() as task
         * loop. 
         * Initialize() and Dispose() methods can be overriden
         * and will be executed by the task only once during creation
         * and destruction of the task.
         */
        class Runnable {
            private:

            TaskHandle_t handle = NULL;
            std::string task_name;
            int priority;
            int stack_size;
            bool end = false;
            Mutex mutex;
            Event end_event;
            
            public:

            /**
             * @brief Construct a new Runnable object
             * 
             * @param task_name The FreeRTOS task name
             * @param priority The task priority [0, configMAX_PRIORITIES - 1]
             * @param stack_size The stack size in words (4 bytes).
             */
            Runnable(const std::string& task_name, int priority, int stack_size) {
                this->task_name = task_name;
                this->priority = priority;
                this->stack_size = stack_size;
            }

            /**
             * @brief Destroy the Runnable object
             * 
             */
            virtual ~Runnable() {
                Stop();
            }

            /**
             * @brief Run task.
             * 
             * @return true Operation success.
             * @return false Operation failed.
             */
            bool Start() {
                bool ret = false;
                AutoMutexLock lock(&mutex);
                //Check if task is already runnin
                if (handle == NULL) {
                    end = false;
                    end_event.Reset();
                    ret = xTaskCreate(
                        Runnable::StartFunction,  
                        task_name.c_str(),        
                        stack_size,     
                        (void*)this,    
                        priority,
                        &handle);
                }
                return ret; 
            }

            /**
             * @brief Stop task asynchronously.
             * 
             */
            void StopAsync() {
                AutoMutexLock lock(&mutex);
                //Set end flag, task will stop but we don't wait for it
                if (handle != NULL) {
                    end = true;
                }
            }

            /**
             * @brief Stop task. Caller gets blocked until task is fully stopped.
             * 
             */
            void Stop() {
                //Stop task asynchronously and wait for end event.
                StopAsync();
                end_event.Wait();
                //Wait for vTaskDelete
                //to be called by the task and resources
                //to be free in FreeRTOS scheduler.
                while (xTaskGetHandle(task_name.c_str()) != NULL) 
                {
                    //Wait 1 tick to give task execution time.
                    vTaskDelay(1);
                }
            }
            
            /**
             * @brief Initialization method executed by task
             * during task start process.
             * 
             * @return true Operation success. Task can run.
             * @return false Operation failed. Task to be stop.
             */
            virtual bool Initialize() {
                return true;
            }

            /**
             * @brief Dispose method executed by task
             * during stop process. 
             * 
             */
            virtual void Dispose() {}

            /**
             * @brief Abstract method where task operation is defined.
             * 
             */
            virtual void Run() = 0;

            private:

            static void StartFunction(void* params) {
                //Runnable is passed as parameter
                Runnable* run_class = (Runnable*)(params);
                if (run_class != NULL) {
                    //Task executes Initialize once before Run() loop.
                    if (run_class->Initialize()) {
                        run_class->mutex.Wait();
                        bool end = run_class->end;
                        run_class->mutex.Release();
                        //While not end flag loop Run()
                        while (!end) {
                            run_class->Run();
                            run_class->mutex.Wait();
                            end = run_class->end;
                            run_class->mutex.Release();
                        }
                        //Dispose task objects
                        run_class->Dispose();
                    }
                    //Reset handle, mutex used as memory barrier
                    run_class->mutex.Wait();
                    run_class->handle = NULL;
                    run_class->mutex.Release();
                    run_class->end_event.Signal();
                }
                //Delete ourselves
                vTaskDelete(NULL);
            }
        };
    }
}
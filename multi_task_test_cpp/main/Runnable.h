
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
                mutex = xSemaphoreCreateRecursiveMutex();
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
                return xSemaphoreTakeRecursive(mutex, timeout_ticks);
            }

            /**
             * @brief Release mutex.
             * 
             * @return true Operation success.
             * @return false Operation failed.
             */
            bool Release() {
                return xSemaphoreGiveRecursive(mutex);
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
            public:
            
            enum eCore {
                CORE0 = 0,
                CORE1 = 1,
                CORE_ANY = 3,
            };

            private:

            TaskHandle_t handle = NULL;
            std::string task_name;
            int priority;
            int stack_size;
            bool end = false;
            eCore affinity;
            mutable Mutex mutex;
            Event end_event;
            
            public:

            
            /**
             * @brief Construct a new Runnable object
             * 
             * @param task_name The FreeRTOS task name
             * @param priority The task priority [0, configMAX_PRIORITIES - 1]
             * @param stack_size The stack size in words (4 bytes).
             * @param affinity CPU core to run task [ CORE0 | CORE1 | CORE_ANY ]
             */
            Runnable(const std::string& task_name, int priority, int stack_size, eCore affinity = eCore::CORE_ANY) {
                this->task_name = task_name;
                this->priority = priority;
                this->stack_size = stack_size;
                this->affinity = affinity;
            }

            /**
             * @brief Destroy the Runnable object
             * 
             */
            virtual ~Runnable() {
                Stop();
            }

            bool IsRunning() const {
                AutoMutexLock lock(&mutex);
                eTaskState state;
                if (handle != NULL) {
                    state = eTaskGetState(handle);
                }else{
                    state = eTaskState::eInvalid;
                }
                return (state != eTaskState::eDeleted && state != eTaskState::eInvalid);
            }

            std::string GetName() const {
                return task_name;
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
                //Check if task is already running
                if (!IsRunning()) {
                    end = false;
                    end_event.Reset();
                    //Start task in FreeRTOS
                    //task runs StartFunction()
                    if (affinity == eCore::CORE_ANY) {
                        ret = xTaskCreate(Runnable::StartFunction,  
                                        task_name.c_str(),        
                                        stack_size,     
                                        (void*)this,    
                                        priority,
                                        &handle);
                    }else{
                        ret = xTaskCreatePinnedToCore(Runnable::StartFunction,  
                                        task_name.c_str(),        
                                        stack_size,     
                                        (void*)this,    
                                        priority,
                                        &handle,
                                        affinity);
                    }
                }
                return ret; 
            }

            /**
             * @brief Stop task asynchronously.
             * 
             */
            void StopAsync() {
                if (IsRunning()) {
                    AutoMutexLock lock(&mutex);
                    //Set end flag, task will stop but we don't wait for it
                    end = true;
                }
            }

            /**
             * @brief Stop task. Caller gets blocked until task is fully stopped.
             * 
             */
            void Stop() {
                if (IsRunning()) {
                    mutex.Wait();
                    //Get current handle, when stopping task handle 
                    //is set to NULL by the task, so we need to save 
                    //it in a temportal variable
                    TaskHandle_t h = handle;
                    //Activate end flag so task end Run() loop
                    end = true;
                    mutex.Release();
                    //End event is signaled in NotifyEnd() by the task
                    end_event.Wait();
                    //Wait for vTaskDelete
                    //to be called by the task and resources
                    //to be free in FreeRTOS scheduler.
                    bool done = false;
                    do 
                    {
                        eTaskState state = eTaskGetState(h);
                        done = (state == eTaskState::eDeleted || state == eTaskState::eInvalid);
                        //Wait 1 tick to give task execution time to end
                        vTaskDelay(1);
                    }while(!done);
                }
            }

            protected:

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
             * @return False if method fails and stop task.
             */
            virtual bool Run() = 0;

            private:

            /**
             * @brief Get the End flag. Mutex used as memory barrier.
             * 
             * @return End flag. 
             */
            bool GetEnd() const {
                AutoMutexLock lock(&mutex);
                return end;
            }

            /**
             * @brief Notify ending task and reset task handle.
             * 
             */
            void NotifyEnd() {
                //Reset handle, mutex used as memory barrier
                AutoMutexLock lock(&mutex);
                handle = NULL;
                end_event.Signal();
            }

            static void StartFunction(void* params) {
                //Runnable object is passed as parameter
                Runnable* run_class = (Runnable*)(params);
                if (run_class != NULL) {
                    //Task executes Initialize once before Run() loop.
                    if (run_class->Initialize()) {
                        //While not end flag loop Run()
                        while (!run_class->GetEnd()) {
                            //Execute Run(), if returns false task ends
                            if (!run_class->Run()) {
                                break;
                            }
                        }
                        //Dispose task objects
                        run_class->Dispose();
                        run_class->NotifyEnd();
                    }
                }
                //Delete ourselves
                vTaskDelete(NULL);
            }
        };
    }
}
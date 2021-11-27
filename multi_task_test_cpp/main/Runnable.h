#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>
#include "sdkconfig.h"
#include <math.h>
#include <stdio.h>

namespace mia {
    namespace rtos {
        #define INFINITE 0xffffffff

        class Mutex {
            private:
            
            SemaphoreHandle_t mutex;

            public:
            Mutex() {
                mutex = xSemaphoreCreateMutex();
            }

            virtual ~Mutex() {
                vSemaphoreDelete(mutex);
            }

            bool Wait(time_t timeout_msec = INFINITE) {
                TickType_t timeout_ticks;
                if (timeout_msec == INFINITE) {
                    timeout_ticks = portMAX_DELAY;
                }else{
                    timeout_ticks = timeout_msec/portTICK_PERIOD_MS;
                }
                return xSemaphoreTake(mutex, timeout_ticks);
            }


            bool Release() {
                return xSemaphoreGive(mutex);
            }
        };

        class Event {
            private:
            SemaphoreHandle_t mutex;

            public:
            Event() {
                vSemaphoreCreateBinary(event);
            }

            virtual ~Event() {
                vSemaphoreDelete(event);
            }

            void Signal() {

            }

            void Wait() {

            }

            void Reset() {

            }
        }

        class AutoMutexLock {
            private:
                Mutex* mutex = NULL;
            public:
                AutoMutexLock(Mutex* m) {
                    this->mutex = m;
                    mutex->Wait();
                }

                virtual ~AutoMutexLock() {
                    mutex->Release();
                }
        };

        class Runnable {
            private:
            TaskHandle_t handle = NULL;
            string task_name;
            int priority;
            int stack_size;
            bool end = false;
            Mutex mutex;
            Event event;
            public:
            Runnable(const string& task_name, int priority, int stack_size) {
                this->task_name = task_name;
                this->priority = priority;
                this->stack_size = stack_size;
            }

            virtual ~Runnable() {
                Stop();
            }

            bool Start() {
                AutoMutexLock lock(&mutex);
                end = false;
                return xTaskCreate(
                    TaskFunctionB,  
                    "TaskB",        
                    stack_size,     
                    (void*)this,    
                    priority,
                    &handle); 
            }

            bool StopAsync() {
                AutoMutexLock lock(&mutex);
                if (handle = NULL) {
                    end = true;
                }
            }

            bool Stop() {
                mutex.Wait();
                bool current_handle = handle;
                mutex.Release();
                if (current_handle != NULL) {
                    end = true;

                }
            }
            
            virtual void Run() = 0;

            private:
            static void StartFunction(void* params) {
                Runnable* run_class = (Runnable*)(params);
                if (run_class != NULL) {
                    mutex.Wait();
                    bool end = run_class->end;
                    mutex.Release();
                    while (!end) {
                        run_class->Run();
                        mutex.Wait();
                        end = run_class->end;
                        mutex.Release();
                    }
                    mutex.Wait();
                    run_class->handle = NULL;
                    mutex.Release();
                }
                vTaskDelete(NULL);
            }
        };
    }
}
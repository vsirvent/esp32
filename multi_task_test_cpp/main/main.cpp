#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>
#include "sdkconfig.h"
#include <math.h>
#include <stdio.h>
#include "Runnable.h"

extern "C" {

using namespace mia::rtos;

#define STACK_SIZE 10*1024

struct data_t {
    float n;
    int i;
};


Mutex mutex;

void TaskFunction( void *pvParameters )
{
    struct data_t* data = (struct data_t*)pvParameters;
    while (true)
    {
        AutoMutexLock lock(&mutex);
        data->i++;
        printf("[%s] task ++ i = %d\n", pcTaskGetName(NULL), data->i);
        if (data->i > 0xffffff) {
            data->i = 0;
        }
    }
    vTaskDelete( NULL );
}

void TaskFunctionB( void *pvParameters )
{
    struct data_t* data = (struct data_t*)pvParameters;
    while (true)
    {
        data->i--;
        mutex.Wait();
        printf("[%s] task -- i = %d\n", pcTaskGetName(NULL), data->i);
        if (data->i > 0xffffff) {
            data->i = 0;
        }
        mutex.Release();
    }

    vTaskDelete( NULL );
}

void app_main(void)
{

    BaseType_t xReturned;
    TaskHandle_t xHandle = NULL;
    volatile struct data_t data;
    data.n = 0.0f;
    data.i = 0;

    /* Create the task, storing the handle. */
    xReturned = xTaskCreate(
                    TaskFunction,       /* Function that implements the task. */
                    "TaskA",          /* Text name for the task. */
                    STACK_SIZE,      /* Stack size in words, not bytes. 200 words*/
                    (void*)&data,    /* Parameter passed into the task. */
                    1,/* Priority at which the task is created. */
                    &xHandle );      /* Used to pass out the created task's handle. */

    
    xReturned = xTaskCreate(
                    TaskFunctionB,       /* Function that implements the task. */
                    "TaskB",          /* Text name for the task. */
                    STACK_SIZE,      /* Stack size in words, not bytes. 200 words*/
                    (void*)&data,    /* Parameter passed into the task. */
                    1,/* Priority at which the task is created. */
                    &xHandle );      /* Used to pass out the created task's handle. */
    while (true) {}
}

}

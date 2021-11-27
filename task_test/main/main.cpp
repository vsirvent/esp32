#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "sdkconfig.h"
#include <math.h>
#include <stdio.h>

extern "C" {

#define STACK_SIZE 10*1024

struct data_t {
    int task_id;
    float n;
    int i;
};


void TaskFunction( void *pvParameters )
{
    struct data_t* data = (struct data_t*)pvParameters;
    while (true)
    {
        data->n = data->i + (float)(data->i*data->i)/(2.0f*(float)data->i);
        if (data->i++ % 10000 == 0) {
            printf("I'm task %d: i = %d, n = %f\n", data->task_id, data->i, data->n);
        }
        if (data->i > 0xffffff) {
            data->i = 0;
        }
    }

    /* Tasks must not attempt to return from their implementing
    function or otherwise exit.  In newer FreeRTOS port
    attempting to do so will result in an configASSERT() being
    called if it is defined.  If it is necessary for a task to
    exit then have the task call vTaskDelete( NULL ) to ensure
    its exit is clean. */
    vTaskDelete( NULL );
}



void app_main(void)
{

    BaseType_t xReturned;
    TaskHandle_t xHandle = NULL;
    struct data_t data;
    data.task_id = 1;
    data.n = 0.0f;
    data.i = 0;
    /* Create the task, storing the handle. */
    xReturned = xTaskCreate(
                    TaskFunction,       /* Function that implements the task. */
                    "TaskA",          /* Text name for the task. */
                    STACK_SIZE,      /* Stack size in words, not bytes. 200 words*/
                    &data,    /* Parameter passed into the task. */
                    1,/* Priority at which the task is created. */
                    &xHandle );      /* Used to pass out the created task's handle. */

    
    while (true) {}
}

}

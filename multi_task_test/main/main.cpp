#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>
#include "sdkconfig.h"
#include <math.h>
#include <stdio.h>

extern "C"
{

#define STACK_SIZE 10 * 1024

    struct data_t
    {
        float n;
        int i;
    };

    SemaphoreHandle_t mutex;

    void TaskFunction(void *pvParameters)
    {
        struct data_t *data = (struct data_t *)pvParameters;
        while (true)
        {
            data->i++;
            printf("[%s:%d] task ++ i = %d\n", pcTaskGetName(NULL), uxTaskPriorityGet(NULL), data->i);
            if (data->i > 0xffffff)
            {
                data->i = 0;
            }
        }

        vTaskDelete(NULL);
    }

    void TaskFunctionB(void *pvParameters)
    {
        struct data_t *data = (struct data_t *)pvParameters;
        while (true)
        {
            data->i--;
            printf("[%s:%d] task -- i = %d\n", pcTaskGetName(NULL), uxTaskPriorityGet(NULL), data->i);
            if (data->i > 0xffffff)
            {
                data->i = 0;
            }
        }
        vTaskDelete(NULL);
    }

    void app_main(void)
    {
        TaskHandle_t task1_handle = NULL;
        TaskHandle_t task2_handle = NULL;
        volatile struct data_t data = {.n = 0.0f, .i = 0};

        mutex = xSemaphoreCreateMutex();

        /* Create the task, storing the handle. */
        xTaskCreate(
            TaskFunction,  /* Function that implements the task. */
            "TaskA",       /* Text name for the task. */
            STACK_SIZE,    /* Stack size in words, not bytes. 200 words*/
            (void *)&data, /* Parameter passed into the task. */
            2,             /* Priority at which the task is created. */
            &task1_handle);     /* Used to pass out the created task's handle. */

        xTaskCreate(
            TaskFunctionB, /* Function that implements the task. */
            "TaskB",       /* Text name for the task. */
            STACK_SIZE,    /* Stack size in words, not bytes. 200 words*/
            (void *)&data, /* Parameter passed into the task. */
            2,             /* Priority at which the task is created. */
            &task2_handle);     /* Used to pass out the created task's handle. */
        while (true)
        {
            printf("[%s:%d] Main app nothing to do\n", pcTaskGetName(NULL), uxTaskPriorityGet(NULL));
        }
    }
}

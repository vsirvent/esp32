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

class TaskA: public Runnable {
private:
    Event* task_event;
public:

    TaskA(Event* event, const std::string& task_name, int priority): Runnable(task_name, priority, STACK_SIZE) 
    {
        this->task_event = event;
    }

protected:

    bool Initialize() override
    {
        printf("TaskA[%s]::Init wait\n", GetName().c_str());
        vTaskDelay(100);
        task_event->Signal();
        return true;
    }

    void Dispose() override
    {
        printf("TaskA[%s]::End\n", GetName().c_str());
    }

    bool Run() override
    {
        //printf("TaskA[%s]::Running...\n", GetName().c_str());
        return true;
    }
};


void app_main(void)
{
    Event event;
    printf("Creation tasks...\n");
    TaskA a1(&event, "my_task_a1", 1);
    TaskA a2(&event, "my_task_a2", 1);
    TaskA a3(&event, "my_task_a3", 1);
    while (true) {
        printf("%d: Running tasks a1...\n", xTaskGetTickCount());
        event.Reset();
        a1.Start();
        printf("%d: Wait tasks a1 init...\n", xTaskGetTickCount());
        event.Wait();
        printf("%d: Running tasks a2...\n", xTaskGetTickCount());
        event.Reset();
        a2.Start();
        printf("%d: Wait tasks a2 init...\n", xTaskGetTickCount());
        event.Wait();
        printf("%d: Running tasks a2...\n", xTaskGetTickCount());
        event.Reset();
        a3.Start();
        printf("%d: Wait tasks a3 init...\n", xTaskGetTickCount());
        event.Wait();
        printf("%d: Waiting...\n", xTaskGetTickCount());
        vTaskDelay(1000);
        printf("%d: Stopping tasks a1...\n", xTaskGetTickCount());
        a1.Stop();
        printf("Stopping tasks a2...\n");
        a2.Stop();
        printf("Stopping tasks a3...\n");
        a3.Stop();
        printf("Stop DONE\n");
        vTaskDelay(1000);
    }
}

}

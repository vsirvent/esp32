#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#define LED1_GPIO CONFIG_LED1_GPIO
#define LED2_GPIO CONFIG_LED2_GPIO

void app_main(void)
{
    gpio_reset_pin(LED1_GPIO);
    gpio_reset_pin(LED2_GPIO);
    /* Set the GPIO as output */
    gpio_set_direction(LED1_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED2_GPIO, GPIO_MODE_OUTPUT);
    while(1) {
        /* Blink off (output low) */
        printf("Turning off the LED\n");
        gpio_set_level(LED1_GPIO, 0);
        gpio_set_level(LED2_GPIO, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        /* Blink on (output high) */
        printf("Turning on the LED\n");
        gpio_set_level(LED1_GPIO, 1);
        gpio_set_level(LED2_GPIO, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

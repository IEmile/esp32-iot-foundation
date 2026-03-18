#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define PIR_PIN GPIO_NUM_14

void app_main(void)
{
    gpio_set_direction(PIR_PIN, GPIO_MODE_INPUT);
    gpio_pulldown_en(PIR_PIN);

    while (1)
    {
        int motion = gpio_get_level(PIR_PIN);

        if (motion)
        {
            printf("🚨 Motion detected!\n");
        }
        else
        {
            printf("No motion\n");
        }

        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

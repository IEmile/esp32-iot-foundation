// #include <stdio.h>
#include "motion_sensor.h"
#include "sensor_data.h"

void init_pir_pin(void)
{
    gpio_set_direction(PIR_PIN, GPIO_MODE_INPUT);
    gpio_pulldown_en(PIR_PIN);
    // gpio_set_intr_type(PIR_PIN, GPIO_INTR_POSEDGE);
    // gpio_install_isr_service(0);
    // gpio_isr_handler_add(PIR_PIN, motion_isr_handler, NULL);
}

void motion_task(void *pv)
{
    int last_motion = 0;

    while (1)
    {
        int motion = gpio_get_level(PIR_PIN);

        xSemaphoreTake(data_mutex, portMAX_DELAY);
        data.motion = motion;
        xSemaphoreGive(data_mutex);

        if (motion && !last_motion)
        {
            printf("🚨 Motion detected!\n");
        }   

        last_motion = motion;

        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

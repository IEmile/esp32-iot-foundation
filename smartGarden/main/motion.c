#include "motion.h"
#include "sensor_data"
#include <stdio.h>

SemaphoreHandle_t motion_semaphore;

static void IRAM_ATTR motion_isr_handler(void* arg)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    xSemaphoreGiveFromISR(motion_semaphore, &xHigherPriorityTaskWoken);

    if (xHigherPriorityTaskWoken)
        portYIELD_FROM_ISR();
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
#include <stdio.h>
#include "freertos/freeRTOS.h" 
#include "freertos/task.h"  
#include "freertos/semphr.h"
#include "sensor_data.h"
#include "motion_sensor.h"
#include "light_sensor.h"
#include "dht_sensor.h"

void app_main(void)
{
    data_mutex = xSemaphoreCreateMutex();
    // motion_semaphore = xSemaphoreCreateBinary();
    init_pir_pin();
    i2c_master_init();

    vTaskDelay(2000 / portTICK_PERIOD_MS); // stabilize sensors by using the longest delay.

    xTaskCreate(motion_task, "motion_task", 2048, NULL, 5, NULL);
    xTaskCreate(dht_task, "dht_task", 4096, NULL, 5, NULL);
    xTaskCreate(light_task, "light_task", 2048, NULL, 5, NULL);
//     xTaskCreate(logic_task, "logic_task", 4096, NULL, 5, NULL);



}











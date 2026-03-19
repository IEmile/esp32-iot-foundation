#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "dht.h"

#define DHT_PIN GPIO_NUM_4

void app_main(void)
{
    float temperature, humidity;

    while (1)
    {
        if (dht_read_float_data(DHT_TYPE_AM2301, DHT_PIN, &humidity, &temperature) == ESP_OK)
        {
            printf("Temperature: %.2f°C | Humidity: %.2f%%\n", temperature, humidity);
        }
        else
        {
            printf("Failed to read from sensor\n");
        }

        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}
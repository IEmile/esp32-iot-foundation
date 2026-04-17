#include "sensor_data.h"
#include "dht_sensor.h"

void dht_task(void* pv)
{
    while(1)
    {
        float temp, hum;

        if (dht_read_float_data(DHT_TYPE, DHT_PIN, &hum, &temp) == ESP_OK)
        {
            xSemaphoreTake(data_mutex, portMAX_DELAY);
            data.temperature = temp;
            data.humidity = hum;
            xSemaphoreGive(data_mutex);
        }
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}
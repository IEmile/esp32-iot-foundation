#include "sensor_data.h"

void logic_task(void* pv){
    int last_motion = 0;

    while (1)
    {
        sensor_data_t local;

        xSemaphoreTake(data_mutex, portMAX_DELAY);
        local = data;
        xSemaphoreGive(data_mutex);

        printf("\n===== SENSOR DATA =====\n");

        printf("Motion: %s\n", local.motion ? "YES" : "NO");
        printf("Temp: %.2f°C\n", local.temperature);
        printf("Humidity: %.2f%%\n", local.humidity);
        printf("Light: %d lux\n", local.lux);

        if (local.motion && !last_motion)
            printf("🚨 Motion detected! logic level\n");

        if (local.motion && local.lux < 50)
            printf("⚠️ Intrusion in darkness\n");

        if (local.temperature > 30)
            printf("🔥 High temperature!\n");

        if (local.humidity > 70)
            printf("💧 High humidity!\n");

        last_motion = local.motion;

        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    
}
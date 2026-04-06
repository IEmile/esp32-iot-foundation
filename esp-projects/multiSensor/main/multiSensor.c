#include <stdio.h> //For printing using uart printf()
#include "driver/gpio.h" //For using PIR pins
#include "driver/i2c.h" // For i2c bus
#include "freertos/freeRTOS.h" //For multi tasking and multi processing
#include "freertos/task.h"     // /\/\// above|
#include "freertos/semphr.h"  //For mutex lock
#include "dht.h"  //For the Humidity temperature sensor. time delays, 
                // mcu/senor handeshake and bit cconversion.
                

SemaphoreHandle_t data_mutex;
SemaphoreHandle_t motion_semaphore;



#define PIR_PIN GPIO_NUM_14 //Define the PIR reading pin
#define DHT_PIN GPIO_NUM_4 //Define the DHT port
#define DHT_TYPE DHT_TYPE_AM2301 //Define the DHT sensor type. 
#define I2C_MASTER_SCL_IO 19
#define I2C_MASTER_SDA_IO 18
#define I2C_MASTER_NUM I2C_NUM_0
#define BH1750_ADDR 0x23


#define TEMP_THRESHOLD 30.0
#define HUM_THRESHOLD 70.0
#define LIGHT_THRESHOLD 50

// static void IRAM_ATTR motion_isr_handler(void* arg)
// {
//     BaseType_t xHigherPriorityTaskWoken = pdFALSE;

//     xSemaphoreGiveFromISR(data_mutex, &xHigherPriorityTaskWoken);

//     if (xHigherPriorityTaskWoken)
//         portYIELD_FROM_ISR();
// }
static void IRAM_ATTR motion_isr_handler(void* arg)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    xSemaphoreGiveFromISR(motion_semaphore, &xHigherPriorityTaskWoken);

    if (xHigherPriorityTaskWoken)
        portYIELD_FROM_ISR();
}

int last_motion = 0;

void i2c_master_init()
{
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = 100000
    };
    i2c_param_config(I2C_MASTER_NUM, &conf);
    i2c_driver_install(I2C_MASTER_NUM, conf.mode, 0, 0, 0);
    uint8_t cmd = 0x10; // continuous mode
    i2c_master_write_to_device(I2C_MASTER_NUM, BH1750_ADDR, &cmd, 1, 1000 / portTICK_PERIOD_MS);
}


int read_light()
{
    // uint8_t cmd = 0x10;
    // i2c_master_write_to_device(I2C_MASTER_NUM, BH1750_ADDR, &cmd, 1, 1000 / portTICK_PERIOD_MS);

    vTaskDelay(500 / portTICK_PERIOD_MS);

    uint8_t data[2];
    i2c_master_read_from_device(I2C_MASTER_NUM, BH1750_ADDR, data, 2, 1000 / portTICK_PERIOD_MS);

    int raw = (data[0] << 8) | data[1];
    return raw / 1.2;
}

// Define a structure to hold all the sensor values. 
// The structure will be accessed by all the sensor process
typedef struct
{
    int motion;
    float temperature;
    float humidity;
    int lux;

} sensor_data_t;

sensor_data_t data;

void motion_task(void* pv)
{
    while(1)
    {
        int motion = gpio_get_level(PIR_PIN);

        if (xSemaphoreTake(data_mutex, portMAX_DELAY))
        {
            data.motion = motion;
            printf("🚨 INTERRUPT: Motion detected!\n");
            xSemaphoreGive(data_mutex);
        }
    }
}
// void motion_task(void *pv)
// {
//     while (1)
//     {
//         if (xSemaphoreTake(data_mutex, portMAX_DELAY))
//         {
//             int motion = gpio_get_level(PIR_PIN);

//             printf("🚨 INTERRUPT: Motion detected!\n");

//             xSemaphoreGive(data_mutex);
//         }
//     }
// }

void dht_task(void* pv)
{
    while(1)
    {
        float temp, hum;

        if (dht_read_float_data(DHT_TYPE_AM2301, DHT_PIN, &hum, &temp) == ESP_OK)
        {
            xSemaphoreTake(data_mutex, portMAX_DELAY);
            data.temperature = temp;
            data.humidity = hum;
            xSemaphoreGive(data_mutex);
        }
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}

void light_task(void* pv){
    while(1)
    {
        int lux = read_light();

        xSemaphoreTake(data_mutex, portMAX_DELAY);
        data.lux = lux;
        xSemaphoreGive(data_mutex);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

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
            printf("🚨 Motion detected!\n");

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



void app_main(void)
{
    data_mutex = xSemaphoreCreateMutex();
    motion_semaphore = xSemaphoreCreateBinary();
    gpio_set_direction(PIR_PIN, GPIO_MODE_INPUT); // Set pir pin as an input pin
    gpio_set_intr_type(PIR_PIN, GPIO_INTR_POSEDGE); //Create an interupt
    gpio_pulldown_en(PIR_PIN); // Add a pull-down on pir pin to set 0 as default
    gpio_install_isr_service(0);
    gpio_isr_handler_add(PIR_PIN, motion_isr_handler, NULL);
    i2c_master_init();

    vTaskDelay(2000 / portTICK_PERIOD_MS); // stabilize sensors by using the longest delay.

    xTaskCreate(motion_task, "motion_task", 2048, NULL, 5, NULL);
    xTaskCreate(dht_task, "dht_task", 4096, NULL, 5, NULL);
    xTaskCreate(light_task, "light_task", 2048, NULL, 5, NULL);
    xTaskCreate(logic_task, "logic_task", 4096, NULL, 5, NULL);
}

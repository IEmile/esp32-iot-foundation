#include <stdio.h> //For printing using uart printf()
#include "driver/gpio.h" //For using PIR pins
#include "driver/i2c.h" // For i2c bus
#include "freertos/freeRTOS.h" //For multi tasking and multi processing
#include "freertos/task.h"     // /\/\// above|
#include "dht.h"  //For the Humidity temperature sensor. time delays, 
                // mcu/senor handeshake and bit cconversion.



#define PIR_PIN GPIO_NUM_14 //Define the PIR reading pin
#define DHT_PIN GPIO_NUM_4 //Define the DHT port
#define DHT_TYPE DHT_TYPE_AM2301 //Define the DHT sensor type. 
#define I2C_MASTER_SCL_IO 22
#define I2C_MASTER_SDA_IO 21
#define I2C_MASTER_NUM I2C_NUM_0
#define BH1750_ADDR 0x23

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
}

int read_light()
{
    uint8_t cmd = 0x10;
    i2c_master_write_to_device(I2C_MASTER_NUM, BH1750_ADDR, &cmd, 1, 1000 / portTICK_PERIOD_MS);

    vTaskDelay(200 / portTICK_PERIOD_MS);

    uint8_t data[2];
    i2c_master_read_from_device(I2C_MASTER_NUM, BH1750_ADDR, data, 2, 1000 / portTICK_PERIOD_MS);

    int raw = (data[0] << 8) | data[1];
    return raw / 1.2;
}



void app_main(void)
{
    gpio_set_direction(PIR_PIN, GPIO_MODE_INPUT); // Set pir pin as an input pin
    gpio_pulldown_en(PIR_PIN); // Add a pull-down on pir pin to set 0 as default
    i2c_master_init();
    float temperature, humidity; // Holding the DHT coverted data
    while(1)
    {
        int motion = gpio_get_level(PIR_PIN); //Read the value of the pir pin
        // Check if the data is being read return ESP_ok if good
        int dht_status = dht_read_float_data(DHT_TYPE_AM2301, DHT_PIN, &humidity, &temperature);

        // Light
        int lux = read_light();

        // Output
        printf("\n===== SENSOR DATA =====\n");

        printf("Motion: %s\n", motion ? "YES" : "NO");

        if (dht_status == ESP_OK)
        {
            printf("Temp: %.2f°C\n", temperature);
            printf("Humidity: %.2f%%\n", humidity);
        }
        else
        {
            printf("Temp/Humidity: ERROR\n");
        }

        printf("Light: %d lux\n", lux);

        printf("=======================\n");

        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }

}

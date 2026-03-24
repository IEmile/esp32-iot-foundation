#include <stdio.h>
#include "driver/i2c.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

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

void bh1750_read()
{
    uint8_t cmd = 0x10; // continuous high-res mode
    i2c_master_write_to_device(I2C_MASTER_NUM, BH1750_ADDR, &cmd, 1, 1000 / portTICK_PERIOD_MS);

    vTaskDelay(200 / portTICK_PERIOD_MS);

    uint8_t data[2];
    i2c_master_read_from_device(I2C_MASTER_NUM, BH1750_ADDR, data, 2, 1000 / portTICK_PERIOD_MS);

    // Print raw bytes
    printf("Raw: 0x%02X 0x%02X\n", data[0], data[1]);
    int raw = (data[0] << 8) | data[1];
    printf("Combined: %d\n", raw);

    int lux = (data[0] << 8) | data[1];
    lux = lux / 1.2;

    printf("Light: %d lux\n", lux);
}

void app_main(void)
{
    i2c_master_init();

    while (1)
    {
        bh1750_read();
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}

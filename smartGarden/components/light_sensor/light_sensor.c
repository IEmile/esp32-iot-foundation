#include "light_sensor.h"
#include "sensor_data.h"

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
    vTaskDelay(500 / portTICK_PERIOD_MS);

    uint8_t data[2];
    i2c_master_read_from_device(I2C_MASTER_NUM, BH1750_ADDR, data, 2, 1000 / portTICK_PERIOD_MS);

    int raw = (data[0] << 8) | data[1];
    return raw / 1.2;
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

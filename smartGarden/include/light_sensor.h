#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include "driver/i2c.h"

#define I2C_MASTER_SDA_IO 18
#define I2C_MASTER_SCL_IO 19
#define I2C_MASTER_NUM I2C_NUM_0
#define BH1750_ADDR 0x23

void i2c_master_init();
int read_light(); 
void light_task(*pv);


#endif
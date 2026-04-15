#ifndef MOTION_SENSOR_H
#define MOTION_SENSOR_H
#include "driver/gpio.h"


#define PIR_PIN GPIO_NUM_14


void init_pir_pin(void);
void motion_task(void* pv);

#endif
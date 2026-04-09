#ifndef MOTION_H
#define MOTION_H

#include "driver/gpio"

#define PIR_PIN GPIO_NUM_14
gpio_set_direction(PIR_PIN, GPIO_MODE_INPUT);
gpio_set_intr_type(PIR_PIN, GPIO_INTR_POSEDGE);
gpio_pulldown_en(PIR_PIN);
int motion_task(*pv);
#endif
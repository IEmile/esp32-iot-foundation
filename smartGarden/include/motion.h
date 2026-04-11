#ifndef MOTION_H
#define MOTION_H

#include "driver/gpio"

#define PIR_PIN GPIO_NUM_14
gpio_set_direction(PIR_PIN, GPIO_MODE_INPUT);
gpio_set_intr_type(PIR_PIN, GPIO_INTR_POSEDGE);
gpio_pulldown_en(PIR_PIN);
void motion_task(*pv);
static void IRAM_ATTR motion_isr_handler(void* arg);
#endif
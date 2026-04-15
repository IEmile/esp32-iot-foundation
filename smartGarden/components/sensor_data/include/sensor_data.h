#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

typedef struct {
    int motion;
    float temperature;
    float humidity;
    int lux;
} sensor_data_t;

extern sensor_data_t data;
extern SemaphoreHandle_t data_mutex;
// extern SemaphoreHandle_t motion_semaphore;



#endif
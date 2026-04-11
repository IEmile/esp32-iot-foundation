#ifdef SENSOR_DATA_H
#define SENSOR_DATA_H

#include "freertos/semphr.h"
typedef struct {
    int motion;
    float temperature;
    float humidity;
    int lux;
} sensor_data_t;

extern sensor_data_t data;

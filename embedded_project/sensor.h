#ifndef SENSOR_H
#define SENSOR_H

#include<time.h>

typedef enum
{
    DEVICE_ERROR = 0,
    DEVICE_OK = 1
}device_status_t;
typedef struct
{
    float temperature;
    float humidity;
    time_t timestamp;
    device_status_t status;
}sensor_t;

void sensor_init(sensor_t *sensor);
void sensor_read(sensor_t *sensor);
void sensor_print(const sensor_t *sensor);
void sensor_alte(const sensor_t *sensor);

#endif




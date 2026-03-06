#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "sensor.h"

static int read_count=0;

void sensor_init(sensor_t *sensor){
    sensor->temperature = 25.34;
    sensor->humidity = 50.00;
    sensor->status = DEVICE_OK;
    sensor->timestamp = time(NULL);
}
void sensor_read(sensor_t *sensor){
    sensor->temperature += (rand() % 5) - 2;
    sensor->humidity += (rand() % 5) - 2;
    sensor->timestamp = time(NULL);
    read_count++;
}
void sensor_print(const sensor_t *sensor){
    printf("\nTime: %s", ctime(&sensor->timestamp));
    printf("Temperature: %.2f\n", sensor->temperature);
    printf("Humidity: %.2f\n", sensor->humidity);
    printf("Status: %d\n", sensor->status);
}
void sensor_alte(const sensor_t *sensor){
    if(sensor->temperature>30){
         printf("WARNING: HIGH TEMPERATURE---temperature: %.2f\n", sensor->temperature);
    }
};


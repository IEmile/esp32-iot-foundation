#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sensor.h"
int main(){
    srand(time(NULL));
    sensor_t sensor;
    sensor_init(&sensor);
    while (1)
    {
        sensor_read(&sensor);
        sensor_print(&sensor);
        sensor_alte(&sensor);

        sleep(5);
    }
    return 0;
}
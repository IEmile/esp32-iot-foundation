#include <stdio.h>
#define DEVICE_OK 1

typedef struct sensor_data
{
    float humidity;
    float temperature;
    int status;
} sensor_data_t;

void sensor_test(const sensor_data_t *data);

int main(){
    sensor_data_t data = {25.5, 60.0, DEVICE_OK};
    sensor_data_t *ptr = &data;
    sensor_test(ptr);
    return 0;
}
void sensor_test(const sensor_data_t *data){
        if(data -> status == DEVICE_OK){
        printf("TEMPERATURE: %.2f \n", data -> temperature);
        printf("HUMIDITY: %.2f \n", data -> humidity);

    }
}

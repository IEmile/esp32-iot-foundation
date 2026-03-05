#include <stdio.h>

typedef enum {
    DEVICE_ERROR = 0,
    DEVICE_OK = 1
} device_status_t;
typedef struct
{
    float humidity;
    float temperature;
    int status;
} sensor_data_t;

void sensor_test(const sensor_data_t *data);

int main(){
    sensor_data_t data = {
    .temperature = 25.5,
    .humidity = 60.0,
    .status = DEVICE_OK
};
    // sensor_data_t *ptr = &data;
    sensor_test(&data);
    return 0;
}
void sensor_test(const sensor_data_t *data){
        if(data->status == DEVICE_OK){
        printf("TEMPERATURE: %.2f \n", data->temperature);
        printf("HUMIDITY: %.2f \n", data->humidity);

    }
}

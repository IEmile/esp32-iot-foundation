#include <stdio.h>
struct sensor_data
{
    float humidity;
    float temperature;
    int status;
};

int main(){
    struct sensor_data sensorData = {25.5, 60.0, 1};
    struct sensor_data *ptr = &sensorData;

    if(ptr->status==1){
        printf("Temperature: %.2f \n", ptr->temperature);
        printf("Humidity: %.2f \n", ptr->humidity);

    }
    return 0;
}
#include<stdio.h>
#include <stdlib.h> 
#include<time.h>
#include <unistd.h>

#define DEVICE_OK 1

typedef struct
{
    float temperature, humidity;
    time_t time;
    int status;
} sensor_t;

void get_sensor_data(const sensor_t *prt);
int main(){
    sensor_t sensor_data = {
        .temperature=26.8,
        .humidity=12.49,
        .status=DEVICE_OK,
        .time=time(NULL)
    };
    int count=0;
    srand(time(NULL));
    printf("\nData at: %s",ctime(&sensor_data.time));
    printf("\nStatus: %d", sensor_data.status);
    printf("\nHumidity: %.2f", sensor_data.humidity);
    printf("\nTemperature: %.2f", sensor_data.temperature);

    while (1)
    {
        sleep(6);
        get_sensor_data(&sensor_data);
        if(count==6){
            break;
        }
        count++;
    }
    
    
    getchar();
    return 0;
}
void get_sensor_data(const sensor_t *ptr){
    time_t currentTime=time(NULL);
    printf("\n\nData at: %s",ctime(&currentTime));
    printf("\nStatus: %d", ptr->status);
    printf("\nHumidity: %.2f", ptr->humidity-rand()%5);
    printf("\nTemperature: %.2f", ptr->temperature-rand()%6);
}
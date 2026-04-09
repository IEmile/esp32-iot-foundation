#include "freertos/semphr.h"
#include "motion.h"
int motion_task(*pv){
    int motionState = 0;
    // while(1){
        if (xSemaphoreTake(motion_semaphore, portMAX_DELAY))
        {
            printf("🚨 INTERRUPT: Motion detected!\n");
            motionState = 1;
        }
    // }
    return motionState;
}
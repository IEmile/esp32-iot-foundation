#include <stdio.h>

typedef enum
{
    STATE_IDLE,
    STATE_MONITORING,
    STATE_MOTION_DETECTED,
    STATE_ALERT_SENT
} system_state_t;

int main()
{
    system_state_t state = STATE_IDLE;

    int motion = 0;

    while(1)
    {
        switch(state)
        {
            case STATE_IDLE:
                printf("System Idle\n");
                state = STATE_MONITORING;
                break;

            case STATE_MONITORING:
                printf("Monitoring sensors\n");
                motion = 1;

                if(motion)
                    state = STATE_MOTION_DETECTED;
                break;

            case STATE_MOTION_DETECTED:
                printf("Motion detected!\n");
                state = STATE_ALERT_SENT;
                break;

            case STATE_ALERT_SENT:
                printf("Alert sent!\n");
                state = STATE_IDLE;
                break;
        }

        getchar();
    }

    return 0;
}
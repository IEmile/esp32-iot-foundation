#include <stdio.h>

typedef enum
{
    EVENT_NONE,
    EVENT_TIMER,
    EVENT_MOTION
} event_t;

void handle_event(event_t event)
{
    switch(event)
    {
        case EVENT_TIMER:
            printf("Timer event: reading sensor\n");
            break;

        case EVENT_MOTION:
            printf("Motion event: sending alert\n");
            break;

        default:
            break;
    }
}

int main()
{
    event_t event;

    while(1)
    {
        printf("\nEnter event (1=timer, 2=motion, 0=exit): ");
        int input;
        scanf("%d",&input);

        if(input==0)
            break;

        if(input==1)
            event = EVENT_TIMER;
        else if(input==2)
            event = EVENT_MOTION;
        else
            event = EVENT_NONE;

        handle_event(event);
    }

    return 0;
}
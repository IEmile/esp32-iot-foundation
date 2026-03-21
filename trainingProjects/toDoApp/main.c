#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct
{
    int id;
    char message[30];
} schedule_t;
bool add_schedule(int* arr, int arrsize, schedule_t* schedule);
bool display_schedules(int* arr, int arrsize, schedule_t* schedule);
bool remove_schedules(int* arr, int arrsize, schedule_t* schedule);

int main()
{
    int arrID[4]={0,0,0,0};
    schedule_t schedule[4];
    int  arrsize = sizeof(arrID) / sizeof(arrID[0]);
    int selection, position;
    //int a;
    if(!display_schedules(arrID, arrsize, schedule))
    {
        printf("You have no schedules on your list.\n");
    }
    while(1)
    {
        //Prompt the user to choose the action; add adding or removing from the list or exiting the program
        printf("Enter Selection 1-3:\n 1: Add Schedule\n 2: Remove Schedule\n 3: Exit\n >");
        scanf("%d", &selection);
        switch(selection)
        {
        case 1:
            //printf("Hello Add world!\n");
            if(add_schedule(arrID, arrsize, schedule))
            {
                printf("Schedule Added!\n");
            }
            break;
        case 2:
            if(remove_schedules(arrID, arrsize, schedule))
            {
                printf("Schedule Removed!\n");
            } else printf("There is no Schedules to Remove!\n");
            break;
        case 3:
            return 0;
        default:
            printf("Invalide Selection\n");
        }
        if(!display_schedules(arrID, arrsize, schedule))
        {
            printf("You have no schedules on your list.\n");
        }
       //printf("ID is: %d\n", schedule.id);
    }
    //printf("Hello world!\n");
   // return 0;
}
bool add_schedule(int* arr, int arrsize, schedule_t* schedule)
{
    //Collect the schedule add from user. Update the arrID to manage and update the schedule.
    //printf("Add schedule\nID:");
   // scanf("%d", &schedule->id);
   // while(getchar() != '\n');
   // printf("Message:");
   // fgets(schedule->message, sizeof(schedule->message), stdin);

    int i;
    for(i=0; i < arrsize; i++)
    {
        if(arr[i] == 0)
        {
            printf("Add schedule\nID:");
            scanf("%d", &schedule[i].id);
            while(getchar() != '\n');
            printf("Message:");
            fgets(schedule[i].message, sizeof(schedule[i].message), stdin);
            arr[i] = schedule->id;
            return 1;
        }
        else if(arr[arrsize-1] != 0)
        {
            printf("full storage\n");
            return 0;
        }
    }
    return 0;
}
bool display_schedules(int *arr, int arrsize, schedule_t* schedule)
{
    printf("Your schedules\n");
    int i, counter = 0;
    for(i=0; i < arrsize; i++)
    {
        if(arr[i] != 0)
        {
            printf("%d: %s\n", schedule[i].id, schedule[i].message);
            counter++;
        }
    }
    if(counter < 1)
    {
        return 0;
    }
    return 1;
}
bool remove_schedules(int* arr, int arrsize, schedule_t* schedule)
{
    int i, a, position;
    printf("Enter the position of the Schedule to remove from 1-10\n");
    printf("Position");
    scanf("%d",&position);
    //for(i=0; i < arrsize; i++)
    //{
        if(arr[0] != 0)
        {
            for(int a = position - 1; a < arrsize - 1; a++)
            {
                schedule[a] = schedule[a + 1];
                arr[a] = arr[a + 1];
            }
            arr[arrsize - 1] = 0;
            //printf("%d: %s\n", schedule.id, schedule.message);
            //arr[position-1]=0;
            //counter++;
            return 1;
        }

    //}
    return 0;
}


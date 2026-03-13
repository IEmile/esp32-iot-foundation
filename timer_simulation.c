#include <stdio.h>
#include <unistd.h>

int main()
{
    int seconds = 0;

    while(1)
    {
        sleep(1);
        seconds++;

        printf("Timer: %d seconds\n", seconds);

        if(seconds % 5 == 0)
        {
            printf("Reading sensor...\n");
        }
    }

    return 0;
}
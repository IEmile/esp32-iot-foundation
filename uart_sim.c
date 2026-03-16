#include <stdio.h>
#include <unistd.h>

void uart_send(const char *message)
{
    printf("UART TX: %s", message);
}

int main()
{
    int temperature = 25;

    while(1)
    {
        char buffer[50];

        sprintf(buffer, "Temperature: %d C\n", temperature);

        uart_send(buffer);

        temperature++;

        sleep(2);
    }

    return 0;
}
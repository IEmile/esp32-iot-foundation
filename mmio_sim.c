#include<stdio.h>
#include <signal.h>
#include<stdint.h>
#include <unistd.h>

uint32_t fake_gpio_register = 0;
#define GPIO (*(volatile uint32_t*)&fake_gpio_register)
typedef enum{
    LED = 3,
    FAN = 2
} reg_pins_t;

void interrupt_handler(int signal)
{
    printf("\nInterrupt received! Motion detected!\n");
}
void led_on()
{
    GPIO |= (1 << 3);
}

void led_off()
{
    GPIO &= ~(1 << 3);
}
void fan_on()
{
    GPIO |= (1<<FAN);
}

void fan_off()
{
    GPIO &= ~(1<<FAN);
}
void print_reg()
{
    printf("GPIO register: %08x\n", GPIO);
}

int main()
{
    signal(SIGINT, interrupt_handler);
    print_reg();

    led_on();
    print_reg();

    led_off();
    print_reg();

    fan_on();
    print_reg();

    fan_off();
    print_reg();
    while(1)
    {
        printf("Main program running...\n");
        sleep(2);
    }

    return 0;
}
#include<stdio.h>


// #define LED_PIN 2
// #define BTN_PIN 5

void gpio_set(int pin)
{
    printf("GPIO %d set HIGH\n", pin);
}
void gpio_clear(int pin)
{
    printf("GPIO %d set LOW\n", pin);
}
// void print_reg(int bit)
// {
//     printf("GPIO register: %08x\n", bit);
// }
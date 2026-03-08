#include <stdio.h>
#include <stdint.h>

volatile uint8_t GPIO_REGISTER = 0;

typedef enum{
    LED_PIN = 3,
    FAN_PIN = 2
} module_pin_t;

void fan_on()
{
    GPIO_REGISTER |= (1 << FAN_PIN);
}
void led_on()
{
    GPIO_REGISTER |= (1 << LED_PIN);
}
void fan_off()
{
    GPIO_REGISTER &= ~(1 << FAN_PIN);
}
void led_off()
{
    GPIO_REGISTER &= ~(1 << LED_PIN);
}
void fan_toggle()
{
    GPIO_REGISTER ^= (1 << FAN_PIN);
}
void led_toggle()
{
    GPIO_REGISTER ^= (1 << LED_PIN);
}

void print_register()
{
    printf("GPIO REGISTER: %08b\n", GPIO_REGISTER);
}

int main()
{
    printf("LED PIN Manipulation\n");
    print_register();

    led_on();
    print_register();
    
    led_off();
    print_register();

    led_toggle();
    print_register();

    printf("FAN PIN Manipulation\n");
    print_register();

    fan_on();
    print_register();

    fan_off();
    print_register();
    
    fan_toggle();
    print_register();

    return 0;
}
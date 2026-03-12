#include "gpio.h"
#include "led.h"
void led_init()
{
    SET_BIT(GPIO, LED_PIN);
}
void led_on()
{
    SET_BIT(GPIO, LED_PIN);
    gpio_set(LED_PIN);
}

void led_off()
{
    CLR_BIT(GPIO, LED_PIN);
    gpio_clear(LED_PIN);
}
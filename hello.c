#include <stdint.h>

/*
Memory mapped register addresses
(simulated addresses similar to MCU GPIO control)
*/

#define GPIO_BASE      0x40020000

#define GPIO_DIR       (*(volatile uint32_t*)(GPIO_BASE + 0x00))
#define GPIO_OUT       (*(volatile uint32_t*)(GPIO_BASE + 0x04))
#define GPIO_IN        (*(volatile uint32_t*)(GPIO_BASE + 0x08))
#define GPIO_SET       (*(volatile uint32_t*)(GPIO_BASE + 0x0C))
#define GPIO_CLR       (*(volatile uint32_t*)(GPIO_BASE + 0x10))

#define LED_PIN 2
#define BTN_PIN 5


/*
Bit macros
*/

#define BIT(x) (1U << (x))

#define SET_BIT(reg, bit)   ((reg) |= BIT(bit))
#define CLR_BIT(reg, bit)   ((reg) &= ~BIT(bit))
#define TOGGLE_BIT(reg, bit) ((reg) ^= BIT(bit))
#define READ_BIT(reg, bit)  (((reg) >> (bit)) & 1U)



/*
Delay function (busy wait)
*/

void delay(volatile uint32_t time)
{
    while(time--)
    {
        __asm__("nop");
    }
}



/*
GPIO initialization
*/

void gpio_init()
{
    /*
    Configure LED_PIN as output
    */

    SET_BIT(GPIO_DIR, LED_PIN);

    /*
    Configure BTN_PIN as input
    */

    CLR_BIT(GPIO_DIR, BTN_PIN);
}



/*
LED control functions
*/

void led_on()
{
    GPIO_SET = BIT(LED_PIN);
}

void led_off()
{
    GPIO_CLR = BIT(LED_PIN);
}

void led_toggle()
{
    TOGGLE_BIT(GPIO_OUT, LED_PIN);
}



/*
Read button state
*/

uint8_t button_pressed()
{
    return READ_BIT(GPIO_IN, BTN_PIN);
}



/*
Bit manipulation example
*/

uint32_t reverse_bits(uint32_t value)
{
    uint32_t result = 0;

    for(int i = 0; i < 32; i++)
    {
        result <<= 1;
        result |= (value & 1);
        value >>= 1;
    }

    return result;
}



/*
Bit count example (Hamming weight)
*/

uint32_t bit_count(uint32_t x)
{
    uint32_t count = 0;

    while(x)
    {
        count += x & 1;
        x >>= 1;
    }

    return count;
}



/*
Main application
*/

int main()
{
    gpio_init();

    uint32_t test = 0x12345678;

    uint32_t reversed = reverse_bits(test);
    uint32_t bits = bit_count(test);

    (void)reversed;
    (void)bits;

    while(1)
    {

        /*
        Poll button
        */

        if(button_pressed())
        {
            led_on();
        }
        else
        {
            led_off();
        }

        /*
        Toggle LED periodically
        */

        led_toggle();

        delay(100000);
    }

    return 0;
}
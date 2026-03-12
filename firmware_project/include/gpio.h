#include<stdint.h>
#ifndef GPIO_H
#define GPIO_H

uint32_t fake_gpio_register = 0;
#define GPIO (*(volatile uint32_t*)&fake_gpio_register)
// #define GPIO_DIR (*(volatile uint32_t*)(GPIO + 0x00))
// #define GPIO_IN (*(volatile uint32_t*)(GPIO_DIR + 0x04))
// #define GPIO_OUT (*(volatile uint32_t*)(GPIO_DIR + 0x08))

#define BIT(X) (1 << X)

#define SET_BIT(reg, bit) ((reg) |= BIT(bit))
#define CLR_BIT(reg, bit) ((reg) &= ~BIT(bit))
#define READ_BIT(reg, bit) ((reg) >> BIT(bit) & 1)
#define TGL_BIT(reg, bit) ((reg) ^= BIT(bit))
void gpio_set(int pin);
void gpio_clear(int pin);

#endif
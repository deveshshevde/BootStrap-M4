

#ifndef LED_H_
#define LED_H_
#include "../source/status.h"

#define GPIOCEN (1<<2)

#define RCC_BASE        0x40023800
#define GPIOC_BASE      0x40020800

#define RCC_AHB1ENR     *((volatile unsigned long *)(RCC_BASE + 30))
#define GPIOC_MODER     *((volatile unsigned long *)(GPIOC_BASE + 0x00))
#define GPIOC_ODR       *((volatile unsigned long *)(GPIOC_BASE + 0x14))


#define GPIOC13         (1 << 13)

status_t init_led(void);

status_t on_led(void);

status_t off_led(void);

#endif /* LED_H_ */

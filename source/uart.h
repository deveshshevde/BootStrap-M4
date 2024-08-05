#ifndef UART_H_
#define UART_H_

#include "status.h"
//for uart
#define GPIOA_BASE     0x40020000
#define GPIOA_MODER  *((volatile unsigned long *)(GPIOA_BASE + 0x00))
#define GPIOA_AFRL   *((volatile unsigned long *)(GPIOA_BASE + 0x20))
#define RCC_APB1ENR  *((volatile unsigned long *)(RCC_BASE + 40))
#define RCC_APB1ENR  *((volatile unsigned long *)(RCC_BASE + 40))

#define USART2_BASE      0x40004400
#define RCC_BASE        0x40023800

#define GPIO_AFRL_AF7_USART2   (0x7)


#define USART2_SR    *((volatile unsigned long *)(USART2_BASE + 0x00))
#define USART2_DR    *((volatile unsigned long *)(USART2_BASE + 0x04))
#define USART2_BRR   *((volatile unsigned long *)(USART2_BASE + 0x08))
#define USART2_CR1   *((volatile unsigned long *)(USART2_BASE + 0x0C))
#define USART2_CR2   *((volatile unsigned long *)(USART2_BASE + 0x10))
#define USART2_CR3   *((volatile unsigned long *)(USART2_BASE + 0x14))


// Bit definitions for GPIOA
#define GPIO_MODER_MODER2_Msk  (0x3 << 4)
#define GPIO_MODER_MODER2_1    (0x2 << 4)
#define GPIO_MODER_MODER3_Msk  (0x3 << 6)
#define GPIO_MODER_MODER3_1    (0x2 << 6)

#define RCC_AHB1ENR_GPIOAEN    (1 << 0)
#define RCC_APB1ENR_USART2EN   (1 << 17)

// Bit definitions for USART2
#define USART_CR1_UE           (1 << 13)
#define USART_CR1_TE           (1 << 3)
#define USART_CR1_RE           (1 << 2)
#define RCC_AHB1ENR     *((volatile unsigned long *)(RCC_BASE + 30))

status_t uart_init();
status_t UART_TRANSMIT(const char *data);

#endif 
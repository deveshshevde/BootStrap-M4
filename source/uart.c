
#include "uart.h"


status_t uart_init()
{

    RCC_AHB1ENR |= RCC_AHB1ENR_GPIOAEN;  // Enable clock for GPIOA
    RCC_APB1ENR |= RCC_APB1ENR_USART2EN; // Enable clock for USART2

    // Configure PA2 and PA3 as Alternate Function for UART2
    GPIOA_MODER &= ~(GPIO_MODER_MODER2_Msk | GPIO_MODER_MODER3_Msk); // Clear mode
    GPIOA_MODER |= (GPIO_MODER_MODER2_1 | GPIO_MODER_MODER3_1);      // Set to Alternate Function mode

    GPIOA_AFRL &= ~((0xF << (2 * 4)) | (0xF << (3 * 4))); // Clear AF settings
    GPIOA_AFRL |= (GPIO_AFRL_AF7_USART2 << (2 * 4)) | (GPIO_AFRL_AF7_USART2 << (3 * 4)); // Set AF7 (USART2) for PA2 and PA3

    // Configure USART2
    USART2_BRR = 0x0683; // Assuming 16 MHz clock, set baud rate to 9600
    USART2_CR1 |= USART_CR1_TE | USART_CR1_RE; // Enable TX and RX
    USART2_CR1 |= USART_CR1_UE;                // Enable USART2
return s_OK;
}


status_t UART_TRANSMIT(const char *data){

    while(*data != '\0'){
        while(!(USART2_SR & (1<<7)));
        USART2_DR = *data;
        data++;
    }
    return s_OK;
}


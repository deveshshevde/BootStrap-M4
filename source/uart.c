
#include "uart.h"

/**
 * Initializes the UART (Universal Asynchronous Receiver/Transmitter) module.
 *
 * @return s_OK if the initialization is successful, otherwise an error code.
 *
 * @throws None
 */
/*
It enables the clock for GPIOA and USART2 using the RCC_AHB1ENR and RCC_APB1ENR registers, respectively.
It configures PA2 and PA3 as Alternate Function for UART2 by setting the corresponding bits in the GPIOA_MODER register.
It sets the AF (Alternate Function) settings for PA2 and PA3 to AF7 (USART2) by modifying the GPIOA_AFRL register.
It configures the USART2 module by setting the baud rate, enabling TX and RX, and enabling USART2 using the USART2_BRR, USART2_CR1, and USART2_CR1 registers, respectively.
Finally, it returns s_OK to indicate that the initialization is successf
*/
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

// Transmits a string of characters via UART.
status_t UART_TRANSMIT(const char *data){

    while(*data != '\0'){
        while(!(USART2_SR & (1<<7)));
        USART2_DR = *data;
        data++;
    }
    return s_OK;
}



#include "../source/status.h"

#include "../source/led.h"

status_t init_led(void){
    

    RCC_AHB1ENR |= GPIOCEN ;
    GPIOC_MODER &= ~(0x3 << 26); 
    GPIOC_MODER |=  (0x1 << 26); 

    return s_OK;
}

status_t on_led(void){

    GPIOC_ODR &= ~GPIOC13;

    return s_OK;
}

status_t off_led(void){

    GPIOC_ODR |= GPIOC13;

    return s_OK;
}
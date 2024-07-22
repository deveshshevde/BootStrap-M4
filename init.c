#include "init.h"





void Null_Interrupt(void){

    return;
}

/**
 * Initializes the SysTick timer to generate interrupts at a frequency of 10kHz.
 *
 * This function sets up the SysTick timer to generate interrupts at a frequency of 10kHz.
 * It calculates the reload value for the SysTick timer based on the core clock frequency.
 * The SysTick timer is then enabled by setting the appropriate bits in the SysTick Control and Status Register (SCSR).
 *
 * @return None.
 *
 * @throws None.
 */
void systick_init(void) {

    // I am taking 10kHz for systick
    uint32_t *SRVR = (uint32_t*)0xE000E014;
	uint32_t *SCSR = (uint32_t*)0xE000E010;
    const int CORE_CLOCK = 84000000;
    *SRVR &= (0x00);
    uint32_t counter = (CORE_CLOCK/10000) - 1;
    *SRVR |= counter;
    *SCSR |= ( 1 << 1); // started systick requests
    *SCSR |= ( 1 << 2);  
    *SCSR |= ( 1 << 0); //starts the counter
};
/**
 * Initializes the system fault handling by enabling the usage fault, bus fault, and memory management fault.
 *
 * @throws None
 */
void sysfault_init(void) {

    uint32_t *SHCSR = (uint32_t*)0xE000ED24;
    *SHCSR |= ( 1 << 18); // Bit 18 USGFAULTENA: Usage fault enable bit, set to 1 to enable (1)
    *SHCSR |= ( 1 << 17); // Bit 17 BUSFAULTENA: Bus fault enable bit, set to 1 to enable (1)
    *SHCSR |= ( 1 << 16); // Bit 16 MEMFAULTENA: Memory management fault enable bit, set to 1 to enable (1)
}

void add_interrupt_handler(uint32_t id, ISR_Handler handler){
    if(id>255)
    {
        return;    
    }
    isr_handlers[id] = handler;
}

void remove_interrupt_handler(uint32_t id){
    if(id>255)
    {
        return;    
    }
    isr_handlers[id] = Null_Interrupt;
}

void Reset_Handler(void){

}
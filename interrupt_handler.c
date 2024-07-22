
typedef unsigned int uint32_t;
typedef void (*ISR_Handler)(void);
#include <stdint.h>

void register_interrupt_handler(uint32_t id, ISR_Handler handler);
void unregister_interrupt_handler(uint32_t id);
void Reset_Handler(void);
void NMI_Handler(void);
void HardFault_Handler(void);
void Default_Handler(void);

extern uint32_t _estack;


__attribute__ ((section(".isr_vector")))
uint32_t vector_table[] = {
    (uint32_t)&_estack,           // Initial Stack Pointer
    (uint32_t)&Reset_Handler,     // Reset Handler
    (uint32_t)&NMI_Handler,       // NMI Handler
    (uint32_t)&HardFault_Handler, // Hard Fault Handler
    // Other interrupt vectors can be added here
    // (uint32_t)&My_IRQHandler, // Custom interrupt handler
};

void Default_Handler(void){
    while(1);
}


/*
    May vary acc. to microcontroller
*/
#define MAX_INTERRUPTS 256


ISR_Handler isr_handlers[MAX_INTERRUPTS];

/**
 * Adds an interrupt handler for the specified interrupt ID.
 * @param id The interrupt ID.
 * @param handler The interrupt handler function to be added.
 * @throws None
 */
void add_interrupt_handler(uint32_t id, ISR_Handler handler) {
    if (id < MAX_INTERRUPTS) {
        isr_handlers[id] = handler;
    }
}

/**
 * Removes the interrupt handler for the specified interrupt ID.
 * @param id The interrupt ID.
 * @return None.
 * @throws None.
 */
void remove_interrupt_handler(uint32_t id) {
    if (id < MAX_INTERRUPTS) {
        isr_handlers[id] = Default_Handler;
    }
}

void Reset_Handler(void){

}
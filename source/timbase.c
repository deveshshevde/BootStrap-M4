#include "timbase.h"
#include "core.h"
volatile uint32_t utick = 0;
void enable_faults(void)
{
	uint32_t *pSHCSR = (uint32_t*)0xE000ED24;

	*pSHCSR |= ( 1 << 16); //mem manage
	*pSHCSR |= ( 1 << 17); //bus fault
	*pSHCSR |= ( 1 << 18); //usage fault
}

void systick_starts(uint32_t tick_hz)
{
    // Pointers to the SysTick Register Value (SRVR) and SysTick Control and Status Register (SCSR)
    uint32_t *pSRVR = (uint32_t*)0xE000E014;
    uint32_t *pSCSR = (uint32_t*)0xE000E010;

    // Calculate the count value based on the system clock frequency and tick frequency
    uint32_t count_value = (84000000U/tick_hz)-1;

    // Clear the current count value in SRVR
    *pSRVR &= ~(0x00FFFFFFFF);

    // Set the new count value in SRVR
    *pSRVR |= count_value;

    // Enable the SysTick timer by setting the ENABLE bit in SCSR
    *pSCSR |= ( 1 << 1); 

    // Enable the SysTick timer interrupt by setting the TICKINT bit in SCSR
    *pSCSR |= ( 1 << 2);  

    // Enable the SysTick timer counter by setting the CLKSOURCE bit in SCSR
    *pSCSR |= ( 1 << 0); 
}

void systick_base(void){
   utick++;
}
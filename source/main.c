


#include "led.h"
#include "uart.h"
#include "printf.h"
void enable_faults(void);
typedef unsigned int uint32_t;
void systick_starts(uint32_t tick_hz);



void systick_starts(uint32_t tick_hz);
void enable_faults(void);
/**
 * The main function of the program.
 *
 * This function initializes faults, starts the system tick timer with a frequency of 1000000 Hz,
 * initializes the LED, and initializes the UART. It then enters an infinite loop, turning on the LED
 * and printing the character 'a' using the custom_print function.
 *
 * @return int The exit status of the program.
 */
int main(void)
{
	enable_faults();
	systick_starts(1000000);	
	if(init_led() == s_OK) {
		on_led();
	};	
	if(uart_init() == s_OK) 
	{
		custom_print("UART DONE");
	}

	
	while(1){
		on_led();
		custom_print("char%c" , 'a');
	}



}


/**
 * Enables faults by setting the appropriate bits in the System Handler Control and State Register (SHCSR).
 *
 * @throws None
 */
void enable_faults(void)
{
	uint32_t *pSHCSR = (uint32_t*)0xE000ED24;

	*pSHCSR |= ( 1 << 16); //mem manage
	*pSHCSR |= ( 1 << 17); //bus fault
	*pSHCSR |= ( 1 << 18); //usage fault
}

/**
 * Initializes the SysTick timer with the specified tick frequency.
 *
 * @param tick_hz The desired tick frequency in Hz.
 *
 * @throws None
 */
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

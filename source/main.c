
#include "led.h"
#include "uart.h"
#include "printf.h"
#include "timbase.h"


typedef unsigned int uint32_t;


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
	DisableInterrupts();;
	enable_faults();
	systick_starts(1000000);	
	if(init_led() == s_OK) {
		on_led();
	};	
	if(uart_init() == s_OK) 
	{
		custom_print("UART DONE");
	}
	EnableInterrupts();

	
	while(1){
		on_led();
		custom_print("char%c" , 'a');
	}

}



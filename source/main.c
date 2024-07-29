
#include<stdio.h>

#include "led.h"
#include "uart.h"
void enable_faults(void);
void systick_starts(uint32_t tick_hz);



int main(void)
{
	enable_faults();
	systick_starts(1000000);	
	if(init_led() != s_OK) {
		on_led();
	};	
}



void enable_faults(void)
{
	uint32_t *pSHCSR = (uint32_t*)0xE000ED24;

	*pSHCSR |= ( 1 << 16); //mem manage
	*pSHCSR |= ( 1 << 17); //bus fault
	*pSHCSR |= ( 1 << 18); //usage fault
}

void systick_starts(uint32_t tick_hz)
{
	uint32_t *pSRVR = (uint32_t*)0xE000E014;
	uint32_t *pSCSR = (uint32_t*)0xE000E010;
    uint32_t count_value = (84000000U/tick_hz)-1;
    *pSRVR &= ~(0x00FFFFFFFF);
    *pSRVR |= count_value;
    *pSCSR |= ( 1 << 1); 
    *pSCSR |= ( 1 << 2);  
    *pSCSR |= ( 1 << 0); 
}

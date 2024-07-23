#include <stdint.h>

#define RAM_START 0x20000000
#define RAM_END   (RAM_START + (96*1024))

#define SRAM_END   (0x20000000 + (128*1024))

#define STACK_START RAM_END

void Reset_Handler();
void NMI_Handler(); __attribute__((alias("Default_Handler")));
void HardFault_Handler(); __attribute__((alias("Default_Handler")));
void MemManage_Handler(); __attribute__((alias("Default_Handler")));
void BusFault_Handler(); __attribute__((alias("Default_Handler")));
void UsageFault_Handler(); __attribute__((alias("Default_Handler")));
void SVC_Handler(); __attribute__((alias("Default_Handler")));
void DebugMon_Handler(); __attribute__((alias("Default_Handler")));
void PendSV_Handler(); __attribute__((alias("Default_Handler")));
void SysTick_Handler(); __attribute__((alias("Default_Handler")));

uint32_t vectors[] = {
    STACK_START,
    (uint32_t)&Reset_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&HardFault_Handler,
    (uint32_t)&MemManage_Handler,
    (uint32_t)&BusFault_Handler,
    (uint32_t)UsageFault_Handler,
    0,
    0,
    0,
    0,
    (uint32_t)&SVC_Handler,
    (uint32_t)&DebugMon_Handler,
    0,
    (uint32_t)&PendSV_Handler,
    (uint32_t)&SysTick_Handler
    



}; __attribute__((section(".vector")))



void Default_Handler(){
    while(1);
}

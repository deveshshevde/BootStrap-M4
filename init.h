typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
typedef unsigned long uintptr_t;
#define MAX_INTERRUPTS 255
extern uint32_t _estack;
void systick_init(void);
// we must have to enable these fault as they are on enabled in default!!
void sysfault_init(void);
void core_interrupt(void);
void Reset_Handler(void);
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

typedef void (*ISR_Handler)(void);
void add_interrupt_handler(uint32_t id, ISR_Handler handler);
void remove_interrupt_handler(uint32_t id);
void Null_Interrupt(void);
ISR_Handler isr_handlers[MAX_INTERRUPTS];

__attribute__ ((section(".isr_vector")))
uint32_t vector_table[] = {
    (uint32_t)(uintptr_t)&_estack,           // Initial Stack Pointer
    (uint32_t)(uintptr_t)&Reset_Handler,     // Reset Handler
    (uint32_t)(uintptr_t)&NMI_Handler,       // NMI Handler
    (uint32_t)(uintptr_t)&HardFault_Handler, // Hard Fault Handler
    (uint32_t)(uintptr_t)&MemManage_Handler, // MPU Fault Handler
    (uint32_t)(uintptr_t)&BusFault_Handler,  // Bus Fault Handler
    (uint32_t)(uintptr_t)&UsageFault_Handler,// Usage Fault Handler
    0, 0, 0, 0,                   // Reserved
    (uint32_t)(uintptr_t)&SVC_Handler,       // SVCall Handler
    (uint32_t)(uintptr_t)&DebugMon_Handler,  // Debug Monitor Handler
    0,                            // Reserved
    (uint32_t)(uintptr_t)&PendSV_Handler,    // PendSV Handler
    (uint32_t)(uintptr_t)&SysTick_Handler,   // SysTick Handler
};
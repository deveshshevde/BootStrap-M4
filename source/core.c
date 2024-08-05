
void DisableInterrupts(void) {
    __asm volatile ("cpsid i");
}

void EnableInterrupts(void) {
    __asm volatile ("cpsie i");
}

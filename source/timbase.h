#pragma once
#include "core.h"
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

extern volatile uint32_t utick;

/**
 * Enables faults by setting the appropriate bits in the System Handler Control and State Register (SHCSR).
 *
 * @throws None
 */
void enable_faults(void);

/**
 * Initializes the SysTick timer with the specified tick frequency.
 *
 * @param tick_hz The desired tick frequency in Hz.
 *
 * @throws None
 */
void systick_starts(uint32_t tick_hz);


void systick_base(void);
#include "samd21g17d.h"
#include <stdint.h>

/*
Cortex-M0+ CMSIS reference:
https://github.com/ARM-software/CMSIS_5/blob/develop/CMSIS/Core/Include/core_cm0plus.h
*/

/*
ms stores the milli second passed so far since systick_init() was called. It's 32-bit integer (SAMD21 mcu core is a 32-bit processor,
so reading ms is an atomic operation, also the maximum value a 32-bit integer can hold is 2^32 - 1, and ms increments
every millisecond, it's maximum value is 2^32 - 1 ms, which is roughly ~ 4 billion. 1 day = 24 * 60 * 60 * 1000 ms; 
4 billion ~ 50 days before ms wraps to 0). Marked as volatile otherwise compiler will cache this value and ms can change
inside an interrupt handler. Marked as static to limit the acess to this variable outside this file to avoid accidental 
overwrite/modification and only exposed to other files as millis() API.
*/
static volatile uint32_t ms = 0;

/*
SysTick_Handler() is a fixed, standard ARM Cortex exception name. Every time the interrupt fires (which is configured
to happen once every 1 ms), the CPU jumps here and increments ms by 1.
*/
void SysTick_Handler(void) {
  ms++;
}

/*
Initialize the SysTick to tick for every 1 ms. Use the core CMSIS api.
*/
void systick_init(uint32_t cpu_hz) {
  SysTick_Config(cpu_hz / 1000);
}

/*
Simple getter function that returns the total elapsed milliseconds since systick_init() was called.
*/
uint32_t get_ms(void) {
  return ms;
}

/*
Delay function. Changed != to < (refer issue #1). Still has dr awbacks for long running systems as overflow
can happen when calculating start + ms. Also added NOP (no operation) line as suggested by @BillisC
*/
void delay_ms(uint32_t ms) {
  uint32_t start = get_ms();
  uint32_t end = start + ms;
  while(get_ms() < end) {
    __NOP();
  }
}

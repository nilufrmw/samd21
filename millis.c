/*
ms returns the milli second passed so far since initial boot. It's 32-bit integer (), marked as volatile otherwise compiler will cache this value
and ms can change inside an interrupt handler. Marked as static to limit the acess to this variable outside this file to avoid accidental 
overwrite/modification to this value.
*/
static volatile uint32_t ms = 0;

void SysTick_Handler(void) {
  ms++;
}

void systick_init(uint32_t cpu_hz) {
  SysTick->LOAD = (cpu_hz / 1000) - 1;
  SysTick->VAL  = 0;
  SysTick->CTRL = 7; // Bits 0, 1, 2 set: ENABLE | TICKINT | CLKSOURCE
}

uint32_t millis(void) {
  return ms;
}

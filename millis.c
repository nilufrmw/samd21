/*
ms returns the milli second passed so far since initial boot. It's 32-bit integer (since the maximum value a 32-bit integer can hold is 2^32 - 1, and ms increments every millisecond, it's maximum value is 2^32 - 1 ms, which is roughly ~ 4 billion. 1 day = 24 * 60 * 60 * 1000 ms; 4 billion ~ 50 days before ms wraps to 0), marked as volatile 
otherwise compiler will cache this value and ms can change inside an interrupt handler. Marked as static 
to limit the acess to this variable outside this file to avoid accidental overwrite/modification to this value.
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

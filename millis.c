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

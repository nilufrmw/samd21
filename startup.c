#include <stdint.h>

void Reset_Handler(void);
void HardFault_Handler(void);
extern int main(void);
extern uint32_t _estack;

/* Vector table matched to linker script */
__attribute__((section(".vectors")))
const void* vector_table[] = {
  (void*) &_estack,
  (void*) Reset_Handler,
  (void*) NMI_Handler,
  (void*) HardFault_Handler
};

/* Executed on reset */
void Reset_Handler(void) {
  /* Branch to main function */
  main();
  
  /* Safe fallback loop if main returns */
  while(1)
    ;
}

void NMI_Handler(void) {
  while(1)
    ;
}

/*
If program crashes, it gets stuck here safely and
we can look inside registers.
*/
void HardFault_Handler(void) {
  while(1)
    ;
}

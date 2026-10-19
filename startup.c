/* Calculate the initial stack pointer value (top of 16KB RAM) */
#define SRAM_START  0x20000000
#define SRAM_SIZE   (16 * 1024)
#define INITIAL_SP  (SRAM_START + SRAM_SIZE)

void Reset_Handler(void);
void HardFault_Handler(void);
extern int main(void);

/* Vector table matched to linker script */
__attribute__((section(".vectors")))
const void* vector_table[] = {
  (void*) &_estack,          // 0x00000000 - Initial Main Stack Pointer (MSP)
  (void*) Reset_Handler,     // 0x00000004
  (void*) 0x0,               // 0x00000008 - NMI
  (void*) HardFault_Handler  // 0x0000000C - HardFault
};

/* Executed on reset */
void Reset_Handler(void) {
  /* Branch to main function */
  main();
  
  /* Safe fallback loop if main returns */
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

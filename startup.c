/* calculate the initial stack pointer value (top of 16KB RAM) */
#define SRAM_START  0x20000000
#define SRAM_SIZE   (16 * 1024)
#define INITIAL_SP  (SRAM_START + SRAM_SIZE)

void reset_handler(void);
void hardfault_handler(void);
extern int main(void);

/* vector table matched to linker script */
__attribute__((section(".vectors")))
const void* vector_table[] = {
  (void*) INITIAL_SP,        // 0x00000000
  (void*) reset_handler,     // 0x00000004
  (void*) 0x0,               // 0x00000008 - NMI
  (void*) hardfault_handler  // 0x0000000C - HardFault
};

/* executed on reset */
void reset_handler(void) {
  /* Branch to main function */
  main();
  
  /* Safe fallback loop if main returns */
  while(1)
    ;
}

/*
if program crashes, it gets stuck here safely and
we can look inside registers.
*/
void hardfault_handler(void) {
  while(1)
    ;
}

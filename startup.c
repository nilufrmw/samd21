/* Calculate the Initial Stack Pointer value (Top of 16KB RAM) */
#define SRAM_START  0x20000000
#define SRAM_SIZE   (16 * 1024)
#define INITIAL_SP  (SRAM_START + SRAM_SIZE)

void reset_handler(void);
void hardfault_handler(void);
extern int main(void);

/* Vector Table matched to address 0x00000000 via Linker Script */
__attribute__((section(".vectors")))
const void* vector_table[] = {
  (void*) INITIAL_SP,        // 0x00000000
  (void*) Reset_Handler,     // 0x00000004
  (void*) 0x0,               // 0x00000008 - placeholder for NMI
  (void*) hardfault_handler  // 0x0000000C - HardFault
};

/* Executed on power-up */
void reset_handler(void) {
  main();
  while(1); // Safe fallback loop if main returns
}

/*
If program crashes, it gets stuck here safely.
We can look inside registers.
*/
void hardfault_handler(void) {
  while(1); 
}

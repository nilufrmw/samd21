/* Calculate the Initial Stack Pointer value (Top of 16KB RAM) */
#define SRAM_START  0x20000000
#define SRAM_SIZE   (16 * 1024)
#define INITIAL_SP  (SRAM_START + SRAM_SIZE)

void Reset_Handler(void);
void HardFault_Handler(void);
extern int main(void);

/* Vector Table matched to address 0x00000000 via Linker Script */
__attribute__((section(".vectors")))
const void* VectorTable[] = {
  (void*) INITIAL_SP,        // 0x00000000
  (void*) Reset_Handler,     // 0x00000004
  (void*) 0x0,               // 0x00000008 - Empty Placeholder for NMI
  (void*) HardFault_Handler  // 0x0000000C - HardFault
};


/* Executed on power-up */
void Reset_Handler(void) {
  main();
  while(1); // Safe fallback loop if main returns
}

/*
If the chip crashes, it gets stuck here safely.
We can look inside registers.
*/
void HardFault_Handler(void) {
  while(1); 
}

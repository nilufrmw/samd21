/* Flash execution only */

ENTRY(Reset_Handler)

MEMORY
{
  FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 128K
  RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 16K
}

/* Stack pointer set to the top of 16 KB SRAM */
_estack = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS
{
  .text :
  {
    KEEP(*(.vectors)) // Vector table placed at 0x00000000
    *(.text*)         // Executable instructions 
    *(.rodata*)       // Read-only constants
  } > FLASH
}

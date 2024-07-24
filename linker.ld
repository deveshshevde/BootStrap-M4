/* #Command for the linker script

# 1-> Entry -> populate entry point into elf -> reset code -> used for debugging
# 2-> Memory
# 3-> Sections -> helps to merge diffrent sections
# 4-> Keep
# 5-> Allign
# 6-> AT

# Location counter -> "." */

ENTRY(Reset_Handler) 


_Min_Heap_Size = 0x200; /* required amount of heap */
_Min_Stack_Size = 0x400; /* required amount of stack */

MEMORY
{
  RAM    (xrw)    : ORIGIN = 0x20000000,   LENGTH = 96K
  FLASH    (rx)    : ORIGIN = 0x80000000,   LENGTH = 512K
}

SECTIONS
{
/* # so here we are going to addup all the text sections of diffrent files lets go
# this section will go into flash because these are all constant value or instruction  */
  .text :
  {
    KEEP(*(.vector))  /* Ensure the vector table is kept in the output */
    *(.text)
    *(.rodata)
    . = ALIGN(4); /* Align to the next 4-byte boundary */
    end_of_text_section = .;
  } > FLASH

/* # we have to know that how much data we have to copy from virtual mem to physical memory */
.data :
{   start_of_vma = .;
    *(.data)
    end_of_vma = .; 
}> RAM AT> FLASH

.bss :
{   start_of_bss = .;
    *(.bss)
    end_of_bss = .;
} > RAM

}
MEMORY
{
    FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 512K
    SRAM (rwx)      : ORIGIN = 0x20000000, LENGTH = 96K
}

SECTIONS
{
    /* Vector table and startup code */
    .isr_vector :
    {
        KEEP(*(.isr_vector))
    } > FLASH

    .stack :
    {
        . = ALIGN(8);
        _estack = .;
        . = . + 0x00000400;
        . = ALIGN(8);
    } > SRAM
}

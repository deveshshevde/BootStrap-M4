ENTRY(Reset_Handler)

MEMORY
{
  SRAM    (xrw)    : ORIGIN = 0x20000000,   LENGTH = 96K
  FLASH    (rx)    : ORIGIN = 0x8000000,   LENGTH = 512K
}


SECTIONS
{

.isr_vector :
  {
    . = ALIGN(4);
    KEEP(*(.isr_vector)) /* Startup code */
    . = ALIGN(4);
  } >FLASH

  .text :
  {
  
    *(.text)
	*(.text.*)
	*(.init)
	*(.fini)
	*(.rodata)
	*(.rodata.*)
	. = ALIGN(4);
	_etext = .;
  }> FLASH
  
  _la_data = LOADADDR(.data);
  
  .data :
  {
    _sdata = .;
	*(.data)
	*(.data.*)
	. = ALIGN(4);
	_edata = .;
  }> SRAM AT> FLASH
  
  .bss :
  {
    _sbss = .;
	__bss_start__ = _sbss;
	*(.bss)
	*(.bss.*)
	*(COMMON)
	. = ALIGN(4);
	_ebss = .;
	__bss_end__ = _ebss;
	   . = ALIGN(4); 
	end = .;
	__end__ = .;
  }> SRAM
  

  
}
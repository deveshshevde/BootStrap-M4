CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0 -Werror  -Wextra -nostdlib -nostdinc -fno-builtin 
LDFLAGS= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T $(SRC_DIR)/linker.ld -Wl,-Map=final.map
LDFLAGS_SH= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=rdimon.specs -T $(SRC_DIR)/linker.ld -Wl,-Map=final.map


SRC_DIR = source



all:main.o led.o stm32_startup.o syscalls.o  printf.o   final.elf
#before link
semi:main.o led.o stm32_startup.o syscalls.o printf.o final_sh.elf  


main.o:$(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -o $@ $^

led.o:$(SRC_DIR)/led.c
	$(CC) $(CFLAGS) -o $@ $^

stm32_startup.o:$(SRC_DIR)/stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^

syscalls.o:$(SRC_DIR)/syscalls.c
	$(CC) $(CFLAGS) -o $@ $^
	
printf.o:$(SRC_DIR)/printf.c
	$(CC) $(CFLAGS) -o $@ $^
	


final.elf: main.o led.o stm32_startup.o printf.o syscalls.o 
	$(CC) $(LDFLAGS) -o $@ $^
	
final_sh.elf: main.o led.o stm32_startup.o printf.o
	$(CC) $(LDFLAGS_SH) -o $@ $^

clean:
	rm -rf *.o *.elf

load:all

	/opt/local/bin/st-flash write final.elf 0x8000000 

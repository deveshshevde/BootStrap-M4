CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0
LDFLAGS= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T linker.ld -Wl,-Map=final.map
LDFLAGS_SH= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=rdimon.specs -T linker.ld -Wl,-Map=final.map

all:main.o init.o  final.elf

semi:main.o init.o final_sh.elf

main.o:main.c
	$(CC) $(CFLAGS) -o $@ $^

init.o:init.c
	$(CC) $(CFLAGS) -o $@ $^
	
final.elf: main.o init.o 
	$(CC) $(LDFLAGS) -o $@ $^
	
final_sh.elf: main.o init.o 
	$(CC) $(LDFLAGS_SH) -o $@ $^

clean:
	rm -rf *.o *.elf



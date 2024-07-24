CC=arm-none-eabi-gcc
Mach=cortex-m4
CFLAGS= -c -mcpu=$(Mach) -mthumb -std=gnu99 -O0 -Wall
LDFLAGS= -nostdlib -T linker.ld -Wl,-Map=final.map

all : main.o led.o startup.o final.elf

main.o:main.c
	$(CC) $(CFLAGS) $^ -o $@

led.o:led.c
	$(CC) $(CFLAGS) $^ -o $@
startup.o:startup.c
	$(CC) $(CFLAGS) $^ -o $@

final.elf: main.o led.o startup.o
	$(CC) $(LDFLAGS) $^ -o $@



dump-main:
	arm-none-eabi-objdump -h main.o

dump-startup:
	arm-none-eabi-objdump -h startup.o
dump-final:
	arm-none-eabi-objdump -h final.elf

clean:
	rm -rf *.o 

CC=arm-none-eabi-gcc
Mach=cortex-m4
CFLAGS= -c -mcpu=$(Mach) -mthumb -std=gnu99 -O0 -Wall


all : main.o led.o startup.o

main.o:main.c
	$(CC) $(CFLAGS) $^ -o $@

led.o:led.c
	$(CC) $(CFLAGS) $^ -o $@
startup.o:startup.c
	$(CC) $(CFLAGS) $^ -o $@

dump-main:
	arm-none-eabi-objdump -h main.o

clean:
	rm -rf *.o 

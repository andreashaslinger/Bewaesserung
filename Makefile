CC = arm-linux-gnueabihf-gcc
STRIP = arm-linux-gnueabihf-strip

all:
	$(CC) -Wall -O2 -ggdb gpio.c water.c -o water -lrt

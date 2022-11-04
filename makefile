CC=gcc
CFLAGS=-Wall -g

all: main

main: modules/fileio.c modules/helper.c modules/inventory.c main.c
	$(CC) $(CFLAGS) -o out modules/fileio.c modules/helper.c modules/inventory.c main.c

clean:
	rm out
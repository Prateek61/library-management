CC=clang
CFLAGS=-Wall -g

all: main

main: modules/fileio.c modules/helper.c modules/inventory.c main.c
	$(CC) $(CFLAGS) -o out modules/fileio.c modules/helper.c modules/inventory.c main.c

test: modules/fileio.c modules/helper.c modules/inventory.c test.c
	$(CC) $(CFLAGS) -o test modules/fileio.c modules/helper.c modules/inventory.c test.c

clean:
	rm out test
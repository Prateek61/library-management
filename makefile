CC=clang
CFLAGS=-Wall -g

all: mainapp

main: helper.c main.c inventory.c
	$(CC) $(CFLAGS) -o out helper.c inventory.c main.c

mainapp: helper.o main.o inventory.o
	$(CC) $(CFLAGS) -o out helper.o inventory.o main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

helper.o: helper.c
	$(CC) $(CFLAGS) -c helper.c

inventory.o: inventory.c
	$(CC) $(CFLAGS) -c inventory.c

clean:
	rm *.o out mainapp
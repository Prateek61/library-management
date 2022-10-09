CC=clang
CFLAGS=-Wall -g

all: mainapp

mainapp: helper.o main.o
	$(CC) $(CFLAGS) -o out helper.o main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

helper.o: helper.c
	$(CC) $(CFLAGS) -c helper.c

clean:
	rm *.o out
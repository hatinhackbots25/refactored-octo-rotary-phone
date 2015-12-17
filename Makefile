CC=gcc
CFLAGS=-W -Wall -ansi
CFILES = gauss.c matrix.c
EXEC=SCEXT2

all: $(EXEC)

SCEXT2: main.o gauss.o matrix.o 
	$(CC) $(CFLAGS) -o $(EXEC) main.o gauss.o matrix.o

main.o : main.c
	$(CC) -c main.c

gauss.o : gauss.c gauss.h
	$(CC) -c gauss.c

matrix.o: matrix.c matrix.h
	$(CC) -c matrix.c

clean:
	rm $(EXEC) *.o *~

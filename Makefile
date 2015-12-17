CC=gcc
CFLAGS=-W -Wall -ansi
CFILES = gauss.c matrix.c
EXEC=SCEXT2

all: $(EXEC)

SCEXT2: gauss.o matrix.o
	$(CC) $(CFLAGS) -o $(EXEC) gauss.o matrix.o

gauss.o : gauss.c gauss.h
	$(CC) -c gauss.c

matrix.o: matrix.c matrix.h
	$(CC) -c matrix.c

clean:
	rm $(EXEC) *.o *~

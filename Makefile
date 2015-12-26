CC=gcc
CFLAGS=-W -Wall -ansi -g
CFILES = gauss.c matrix.c add_crypt_clear.c
EXEC=SCEXT2

all: $(EXEC)

SCEXT2: main.o gauss.o matrix.o add_crypt_clear.o 
	$(CC) $(CFLAGS) -o $(EXEC) main.o gauss.o matrix.o add_crypt_clear.o

add_crypt_clear.o: add_crypt_clear.c add_crypt_clear.h
	$(CC) -c add_crypt_clear.c

main.o : main.c
	$(CC) -c main.c

gauss.o : gauss.c gauss.h
	$(CC) -c gauss.c

matrix.o: matrix.c matrix.h
	$(CC) -c matrix.c

clean:
	rm $(EXEC) *.o *~ *#

CC = gcc
CFLAGS = -g -Wall -std=c99
all: playground 
playground: playground.o
	$(CC) $(CFLAGS) -o playground playground.o

playground.o: playground.c
	$(CC) $(CFLAGS) -c playground.c
clean: 
	$(RM) $(all)

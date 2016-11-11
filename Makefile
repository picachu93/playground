CC = gcc
CFLAGS = -g -Wall -std=c99
all: test 
test: test.o
	$(CC) $(CFLAGS) -o test test.o

test.o: test.c
	$(CC) $(CFLAGS) -c test.c
clean: 
	$(RM) $(all)

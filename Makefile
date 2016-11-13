CC = gcc
CFLAGS = -g -Wall -std=c99
all: playg 
playg: playg.o
	$(CC) $(CFLAGS) -o playg playg.o

playg.o: playg.c
	$(CC) $(CFLAGS) -c playg.c
clean: 
	$(RM) $(all)

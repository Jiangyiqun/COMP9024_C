# Makefile for listIteratorInt 

CC = gcc
CFLAGS = -Wall -Werror -g

all : components

components : components.o Graph.o 
	$(CC) $(CFLAGS) -o components  components.o Graph.o

components.o: components.c Graph.h

Graph.o : Graph.c  Graph.h

clean :
	rm -f *.o *.exe components

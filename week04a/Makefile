# Makefile for listIteratorInt 

CC = gcc
CFLAGS = -Wall -Werror -g

all : component

component : component.o Graph.o 
	$(CC) $(CFLAGS) -o component  component.o Graph.o

component.o: component.c Graph.h

Graph.o : Graph.c  Graph.h

clean :
	rm -f *.o *.exe component

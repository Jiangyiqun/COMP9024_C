# Makefile for listIteratorInt 

CC = gcc
CFLAGS = -Wall -Werror -g

all : graphAnalyser

graphAnalyser : graphAnalyser.o Graph.o 
	$(CC) $(CFLAGS) -o graphAnalyser  graphAnalyser.o Graph.o

graphAnalyser.o: graphAnalyser.c Graph.h

Graph.o : Graph.c  Graph.h

clean :
	rm -f *.o *.exe graphAnalyser

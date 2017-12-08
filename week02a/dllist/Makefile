# COMP9024 18x1

CC=gcc
CFLAGS=-Wall -Werror


testL : testList.o DLList.o
	$(CC) -o testL testList.o DLList.o

DLList.o : DLList.c DLList.h
	$(CC) -c  DLList.c

testList.o : testList.c DLList.h
	$(CC) -c  testList.c

clean:
	rm -f testL  *.o core

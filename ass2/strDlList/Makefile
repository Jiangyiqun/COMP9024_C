# COMP9024 18x1

CC=gcc
CFLAGS=-Wall -Werror


testL : testList.o strDlList.o
	$(CC) -o testL testList.o strDlList.o

DLList.o : strDlList.c strDlList.h
	$(CC) -c  strDlList.c

testList.o : testList.c strDlList.h
	$(CC) -c  testList.c

clean:
	rm -f testL  *.o core

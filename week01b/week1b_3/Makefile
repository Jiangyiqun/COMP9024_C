binary: binary.o Stack.o 
	gcc -o binary binary.o

binary.o: binary.c Stack.c
	gcc -Wall -Werror -c binary.c

Stack.o: Stack.c Stack.h
	gcc -Wall -Werror -c Stack.c

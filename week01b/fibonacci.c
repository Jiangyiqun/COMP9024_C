// Author: Jack Jiang (z5129432@student.unsw.edu.au)
// Date: 2 Dec 2017
/* COMP9024 problem set Week 1a, 1


The Fibonacci numbers are defined as follows:

    Fib(1) = 1
    Fib(2) = 1
    Fib(n) = Fib(n-1)+Fib(n-2) for n≥3 

Write a C program fibonacci.c that applies the process described in Part a. to the first 10 Fibonacci numbers.
The output of the program should begin with
Fib[1] = 1
1
Fib[2] = 1
1
Fib[3] = 2
2
1
Fib[4] = 3
3
10
5
16
8
4
2
1
*/

#include <stdio.h>
#include <stdlib.h>

int convert(int n);
int fib(int n);

int main(void) {
    int i;
    int n;
    for (i = 1; i <= 10; i++) {
        n = fib(i);
        printf("Fib[%d] = %d\n%d\n", i, n, n);
        while (n != 1) {
            n = convert(n);
            printf("%d\n", n);
        }
    }
    return EXIT_SUCCESS;
}

int convert(int n) {
    if (n % 2 == 0) {
        n = n / 2;
    } else {
        n = 3 * n + 1;
    }
    return n;
}

int fib(int n) {
    int result = 1;
    if (n >= 3) {
        result = fib(n -1) + fib(n - 2);
    } else {
        result = 1;
    }
    return result;
}
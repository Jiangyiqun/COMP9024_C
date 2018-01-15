// Author: Jack Jiang (z5129432@student.unsw.edu.au)
// Date: 2 Dec 2017
/* COMP9024 problem set
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    int i = 2;
    unsigned long long int* fib = malloc(sizeof(unsigned long long int) * n);
    fib[0] = 1;
    fib[1] = 1;
    for (i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i -2];
    }
    printf("fib %d = %lld\n", n, fib[n - 1]);
    return EXIT_SUCCESS;
}

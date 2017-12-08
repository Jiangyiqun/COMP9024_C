// Author: Jack Jiang (z5129432@student.unsw.edu.au)
// Date: 2 Dec 2017
/* COMP9024 problem set
*/

#include <stdio.h>
#include <stdlib.h>
#include "Stack.c"

int main(int argc, char* argv[]) {
    StackInit();
    int n = atoi(argv[1]);
    //printf("%d\n", n);
    while (n > 0) {
        StackPush(n % 2);
        n = n /2;
    }
    //printf("%d\n", n);
    while (StackIsEmpty() == 0) {
        printf("%d", StackPop());
    }
    printf("\n");
    return EXIT_SUCCESS;
}
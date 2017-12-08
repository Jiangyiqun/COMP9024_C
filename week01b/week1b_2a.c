// Author: Jack Jiang (z5129432@student.unsw.edu.au)
// Date: 2 Dec 2017
/* COMP9024 problem set
*/

#include <stdio.h>
#include <stdlib.h>
#include "Stack.c"



int main(void) {
    int n = 0;
    int ch = 0;
    int i = 0;
    StackInit();
    printf("Enter a positive number:");
    scanf("%d", &n);
    for (i = 0; i < 3; i++) {
        printf("Enter a number:");
        scanf("%d", &ch);
        StackPush(ch);
    }
    for (i = 0; i < 3; i++) {
        ch = StackPop();
        printf("%d\n", ch);
    }
    return EXIT_SUCCESS;
}
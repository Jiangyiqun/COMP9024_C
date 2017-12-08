
// Author: Jack Jiang (z5129432@student.unsw.edu.au)
// Date: 2 Dec 2017
/* COMP9024 problem set
*/

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"



int main(int argc, char* argv[]) {
    argc --;    // minutes program name itself
    int i = 0;
    int ch;
    StackInit();
    for (i = 0; i < argc; i++) {
        StackPush(atoi(argv[i + 1]));
    }
    for (i = 0; i < argc; i++) {
        ch = StackPop();
        printf("%d\n", ch);
    }
    return EXIT_SUCCESS;
}
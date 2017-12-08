// Author: Jack Jiang (z5129432@student.unsw.edu.au)
// Date: 2 Dec 2017
/* COMP9024 problem set
good
goo
go
g
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int n = strlen(argv[1]);    // the size of input string
    for (int i = n - 1; i >= 0; i--) {
        printf("%s\n", argv[1]);
        argv[1][i] = '\0';      // delete the last charactor
    }
    return EXIT_SUCCESS;
}
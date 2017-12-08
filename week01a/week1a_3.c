// Author: Jack Jiang (z5129432@student.unsw.edu.au)
// Date: 2 Dec 2017
/* COMP9024 problem set Week 1a, 1
There is a 5-digit number that satisfies 4·abcde = edcba,
that is, when multiplied by 4 yields the same number read backwards.
Write a C-program to find this number.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int noChar = 6;
    int noStr = 1;
    int i;
    for (i = noChar; i > 0; i--) {
        noStr *= i;
    }
    printf("the number of string is %d\n", noStr);
    return EXIT_SUCCESS;
}
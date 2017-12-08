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
    int i;
    for (i = 10000; i < 100000; i++) {
        if (i * 4 == (i / 10000) + (i % 10000 / 1000 * 10) + (i % 1000 / 100 * 100) + (i % 100 / 10 * 1000) + (i % 10 * 10000)) {
            printf("%d * 4 = %d\n", i, i * 4);
        };
    };
    return EXIT_SUCCESS;
}
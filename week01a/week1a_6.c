// Author: Jack Jiang (z5129432@student.unsw.edu.au)
// Date: 2 Dec 2017
/* COMP9024 problem set
*/

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b, int c);

int main(void) {
    int a = 1;
    int b = 3;
    int c = 2;
    printf("the largest number among %d %d and %d is %d\n", a, b, c, max(a, b, c));
    return EXIT_SUCCESS;
}

int max(int a, int b, int c) {
   int d = a * (a >= b) + b * (a < b);   // d is max of a and b
   return  c * (c >= d) + d * (c < d);   // return max of c and d
}
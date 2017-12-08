// Author: Jack Jiang (z5129432@student.unsw.edu.au)
// Date: 2 Dec 2017
/* COMP9024 problem set Week 1a, 2a
Write a C-function that returns the inner product of two n-dimensional vectors a and b, 
encoded as 1-dimensional arrays of n floating point numbers.
Use the function prototype float innerProduct(float a[], float b[], int n).
Hint: The inner product of two vectors is calculated as `sum_(i=1..n)bb"a"_(i)*bb"b"_(i)`
*/

#include <stdio.h>
#include <stdlib.h>

float innerProduct(float a[], float b[], int n);

int main(void) {
    float a[] = {1, 2, 3, 4, 5};
    float b[] = {5, 4, 3, 2, 1};
    int n = 5;
    float result;
    result = innerProduct(a, b, n);
    printf("%f\n", result);
    return EXIT_SUCCESS;
}

float innerProduct(float a[], float b[], int n) {
    float sum = 0;
    int i = 0;
    for (i = 0; i < n; i++) {
        sum += a[i] * b[i]; 
    }
    return sum;
}
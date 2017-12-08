// Author: Jack Jiang (z5129432@student.unsw.edu.au)
// Date: 2 Dec 2017
/* COMP9024 problem set Week 1a, 2a
Write a C-function to compute C as the matrix product of matrices A and B.

Use the function prototype void matrixProduct(float a[M][N], float b[N][P], float c[M][P]).
You can assume that M, N, P are given as symbolic constants, e.g.

#define M 3
#define N 4
#define P 4

Hint: The product of an m×n matrix A and an n×p matrix B is the m×p matrix C such that 
C(ij) = sum_(k=1..n) A(ik)*B(kj)  for all i∈{1..m} and j∈{1..p}.

*/

#include <stdio.h>
#include <stdlib.h>

#define M 3
#define N 4
#define P 4

void matrixProduct(float a[M][N], float b[N][P], float c[M][P]);

int main(void) {
    float a[M][N] = {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4}
    };
    float b[N][P] = {
        {5, 6, 7, 8},
        {5, 6, 7, 8},
        {5, 6, 7, 8},
        {5, 6, 7, 8}
    };
    float c[M][P];
    matrixProduct(a, b, c);
    return EXIT_SUCCESS;
}

void matrixProduct(float a[M][N], float b[N][P], float c[M][P]) {
    int i = 0;
    int j = 0;
    int k = 0;
    for (i = 0; i < M; i++) {
        for (j =0; j < P; j++) {
            c[i][j] = 0;
            for (k =0; k < N; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("c[%d][%d] = %f\n", i + 1, j + 1, c[i][j]);
        }
    }
}
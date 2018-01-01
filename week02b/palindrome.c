// Author: Jack Jiang 
// Email: z5129432@student.unsw.edu.au
// Date: 2 Dec 2017
/* for COMP9024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(int argc, char *argv[]) {
    assert(argc == 2);
    int n = (int)strlen(argv[1]);
    int i;
    for (i = 0; i < n; i++) {
        if (argv[1][i] != argv[1][n - i - 1]) {
            printf("no\n");
            return EXIT_SUCCESS;
        }
    }
    printf("yes\n");
    return EXIT_SUCCESS;
}

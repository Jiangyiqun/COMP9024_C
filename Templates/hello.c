// Author: Jack Jiang 
// Email: z5129432@student.unsw.edu.au
// Date: 2 Dec 2017
/* for COMP9024
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(void) {
    char word[50] = "hello world";
    word[10] = '\0';
    printf("%s\n", word);
    return EXIT_SUCCESS;
}

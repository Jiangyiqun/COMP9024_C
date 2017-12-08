/* Makes an array of 10 integers and returns a pointer to it */
// it is wrong because the array will be destroyed agter the function called
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int* makeArrayOfInts(void) {
    int* arr;
    arr = malloc(sizeof(int) * 10);
    assert(arr != NULL);
    return arr;
}
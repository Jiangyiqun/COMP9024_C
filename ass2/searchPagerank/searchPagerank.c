// File: searchPagerank.c
// Author: Jack Jiang (z5129432)
// Data: 2018x1
// Description:
//     for COMP9024 Assignment 2
// Reference:
//     https://www.cse.unsw.edu.au/~cs9024/18x1/assn/assn2/Ass2.html

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include "searchPagerank.h"

#define MAX_URL_LENGTH 6    // 5 char plus a terminator
#define MAX_WORD_LENGTH 50

int main(int argc, char *argv[]) {
    int nURL = getURLNumber();
    char *URLList = createURLList(nURL);
    
    return EXIT_SUCCESS;
}


int getURLNumber() {
    int nURL = 0;
    char url[MAX_URL_LENGTH];
    FILE *collection = fopen("collection.txt", "r");
    while (fscanf(collection, "%s", url) != EOF) {
        nURL++;
    }
    fclose(collection);
    return nURL;
}


char *createURLList(int nURL) {
    char url[MAX_URL_LENGTH];
    int i;
    char *URLList = malloc(sizeof(char) * MAX_URL_LENGTH * nURL);
    assert(URLList != NULL);
    FILE *collection = fopen("collection.txt", "r");
    for (i = 0; fscanf(collection, "%s", url) != EOF; i ++) {
        strcpy(&URLList[i * MAX_URL_LENGTH], url);
    }
    fclose(collection);
    // debug
    // printf("The %d URLList is:\n", nURL);
    // for (i =0; i < nURL * MAX_URL_LENGTH; i += MAX_URL_LENGTH) {
    //     printf("    %s\n", &URLList[i]);
    // }
    return URLList;
}
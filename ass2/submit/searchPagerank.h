// File: searchPagerank.h
// Author: Jack Jiang (z5129432)
// Data: 2018x1
// Description:
//     for COMP9024 Assignment 2
// Reference:
//     https://www.cse.unsw.edu.au/~cs9024/18x1/assn/assn2/Ass2.html

#ifndef SEARCH_PAGERANK_H
#define SEARCH_PAGERANK_H

// a structure used to create indexList
typedef struct indexList {
    char URL[MAX_URL_LENGTH];
    float PR;
} indexList;

// get the number of URL
int getNumberOfURL();

// read url from invertedList.txt into a double linked list
// return the address of the double linked list
indexList* readInvertedIndex(int nURL);

// show the top maxLine page of indexList
void showInvertedIndex(indexList* myList, int nURL);

// sort the indexList by PR
indexList* sortInvertedIndex(indexList* myList, int nURL);

#endif

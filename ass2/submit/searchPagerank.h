// File: searchPagerank.h
// Author: Jack Jiang (z5129432)
// Data: 2018x1
// Description:
//     for COMP9024 Assignment 2
// Reference:
//     https://www.cse.unsw.edu.au/~cs9024/18x1/assn/assn2/Ass2.html

#ifndef SEARCH_PAGERANK_H
#define SEARCH_PAGERANK_H

// read url from invertedList.txt into a double linked list
// return the address of the double linked list
DLList readInvertedIndex();

// show the top maxLine page of indexList
void showInvertedIndex(DLList indexList);

#endif

// File: searchPagerank.h
// Author: Jack Jiang (z5129432)
// Data: 2018x1
// Description:
//     for COMP9024 Assignment 2
// Reference:
//     https://www.cse.unsw.edu.au/~cs9024/18x1/assn/assn2/Ass2.html

#ifndef SEARCH_PAGERANK_H
#define SEARCH_PAGERANK_H

// return the number of URLs in collection.txt
int getURLNumber();

// create a array of URL, and return its address
char *createURLList(int nURL);


#endif
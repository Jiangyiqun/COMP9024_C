// File: invertedIndex.h
// Author: Jack Jiang (z5129432)
// Data: 2018x1
// Description:
//     for COMP9024 Assignment 2
// Reference:
//     https://www.cse.unsw.edu.au/~cs9024/18x1/assn/assn2/Ass2.html

#ifndef INVERTEDINDEX_H
#define INVERTEDINDEX_H

// return the number of URLs in collection.txt
int getURLNumber();

// create a array of URL, and return its address
char *createURLList(int nURL);

// read words form urlxx.txt
int readIndex(char *URLList, int nURL);

// normalise word, which will do these two things:
// 1. converting all characters to lowercase,
// 2. remove trailing punctuation, including:
//      '.' (dot), ',' (comma), ';' (semicolon), ? (question mark) 
char *normalise(char* word);

#endif
// File: strDlList.h
// Author: 
//	 Written by John Shepherd, March 2013
// 	 Modified by John Shepherd, August 2014, August 2015
//	 Modified by Ashesh Mahidadia, December 2017 
//	 Modified by Jack Jiang (z5129432), Jan 2018
// Data: 2018x1
// Description:
//	 Implementation of doubly-linked list of string
//   for COMP9024 Assignment 2
// Reference:
//     https://www.cse.unsw.edu.au/~cs9024/18x1/slides/week02a/progs/dllist.zip

#ifndef DLLIST_H
#define DLLIST_H

// External view of DLList
// Implementation given in DLList.c
// Implements a DLList of integers 

typedef struct DLListRep *DLList;

// create a new empty DLList
DLList newDLList();

// free up all space associated with list
void freeDLList(DLList);

// reset curr to first
void resetDLList(DLList L);

// move curr to next and return next
void moveNextDLList(DLList L);

// display items from a DLList, comma separated
void showDLList(DLList L);

// display items from a DLList, space separated
void showDLListWithoutComma(DLList L);

// return item at current position
char *DLListCurrent(DLList);

// insert an item after current item
// new item becomes current item
void DLListAfter(DLList L, char *it);

// delete current item
// new item becomes item following current
// if current was last, current becomes new last
// if current was only item, current becomes null
void DLListDelete(DLList);

// return number of elements in a list
int DLListLength(DLList);

// is the list empty?
int DLListIsEmpty(DLList);

#endif

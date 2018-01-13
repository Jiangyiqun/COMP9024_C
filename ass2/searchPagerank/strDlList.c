// File: strDlList.c
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



#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "strDlList.h"

#define STRING_LENGTH 10	// the max string length


// data structures representing DLList
typedef struct DLListNode {
	char   value[STRING_LENGTH];  // value of this list item (string)
	struct DLListNode *prev;
	               // pointer previous node in list
	struct DLListNode *next;
	               // pointer to next node in list
} DLListNode;


typedef struct DLListRep {
	int  nitems;      // count of items in list
	DLListNode *first; // first node in list
	DLListNode *curr;  // current node in list
	DLListNode *last;  // last node in list
} DLListRep;


// create a new DLListNode (private function)
static DLListNode *newDLListNode(char *it)
{
	DLListNode *new;
	new = malloc(sizeof(DLListNode));
	assert(new != NULL);
	strcpy(new->value, it);
	new->prev = new->next = NULL;
	return new;
}

// create a new empty DLList
DLList newDLList()
{
	struct DLListRep *L;
	L = malloc(sizeof (struct DLListRep));
	assert (L != NULL);
	L->nitems = 0;
	L->first = NULL;
	L->last = NULL;
	L->curr = NULL;
	return L;
}

// free up all space associated with list
void freeDLList(DLList L)
{
	assert(L != NULL);
	DLListNode *curr, *prev;
	curr = L->first;
	while (curr != NULL) {
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	free(L);
}

// reset curr to first
void resetDLList(DLList L) {
	assert(L != NULL);
	L->curr = L->first;
}

void moveNextDLList(DLList L) {
	assert(L != NULL);
	L->curr = L->curr->next;
}



// display items from a DLList, comma separated
void showDLList(DLList L)
{
	assert(L != NULL);
	DLListNode *curr;
	int count = 0;
	for (curr = L->first; curr != NULL; curr = curr->next){
		count++;
		if(count > 1) {
			fprintf(stdout,", ");
		}
		fprintf(stdout,"%s",curr->value);
	}
	fprintf(stdout,"\n");
}


// return item at current position
char *DLListCurrent(DLList L)
{
	assert(L != NULL); assert(L->curr != NULL);
	return L->curr->value;
}


// insert an item after current item
// new item becomes current item
void DLListAfter(DLList L, char *it)
{
	assert(L != NULL); 
	DLListNode *new = newDLListNode(it);
	assert(new != NULL);
	if (L->first == NULL && L->last == NULL) {
		L->curr = L->first = L->last = new;
	}
	else if (L->curr == L->last) {
		new->prev = L->last;
		L->last->next = new;
		L->curr = L->last = new;
	}
	else {
		new->prev = L->curr;
		new->next = L->curr->next;
		L->curr->next->prev = new;
		L->curr->next = new;
	}
	L->curr = new;
	L->nitems++;
}

// delete current item
// new item becomes item following current
// if current was last, current becomes new last
// if current was only item, current becomes null
void DLListDelete(DLList L)
{
	assert (L != NULL);
	DLListNode *old = L->curr;
	if (L->nitems == 0 || old == NULL) {
		// should we flag an error here?
		return;
	}
	else if (old == L->first && old == L->last) {
		// remove only node in list
		L->curr = L->first = L->last = NULL;
	}
	else if (old == L->first) {
		// remove first node
		old->next->prev = NULL;
		L->curr = L->first = old->next;
	}
	else if (old == L->last) {
		// remove last node
		old->prev->next = NULL;
		L->curr = L->last = old->prev;
	}
	else {
		// remove node from "middle" of list
		old->prev->next = old->next;
		old->next->prev = old->prev;
		L->curr = old->next;
	}

	free(old);
	L->nitems--;
}

// return number of elements in a list
int DLListLength(DLList L)
{
	return (L->nitems);
}

// is the list empty?
int DLListIsEmpty(DLList L)
{
	return (L->nitems == 0);
}


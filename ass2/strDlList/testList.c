// File: testList.c
// Author: 
//	 Written by Ashesh Mahidadia, December 2017 
//	 Modified by Jack Jiang (z5129432), Jan 2018
// Data: 2018x1
// Description:
//	 Implementation of doubly-linked list of string tester
//   for COMP9024 Assignment 2
// Reference:
//     https://www.cse.unsw.edu.au/~cs9024/18x1/slides/week02a/progs/dllist.zip


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "strDlList.h"

int main(int argc, char *argv[])
{
	DLList myList = newDLList();
	DLListAfter( myList, "url10");
	DLListAfter( myList, "url11");
	DLListAfter( myList, "url12");
	DLListAfter( myList, "url13");
	DLListAfter( myList, "url14");
	printf("This is my list\n");
	showDLList(myList);



	printf("reset to the first value\n");	resetDLList(myList);
	printf("Deleting current value\n"); 	DLListDelete(myList);
	printf("move to next node\n"); 	moveNextDLList(myList);
	printf("Deleting current value\n"); 	DLListDelete(myList);
	printf("move to next node\n"); 	moveNextDLList(myList);
	printf("Deleting current value\n"); 	DLListDelete(myList);


	printf("reset to the first value\n"); resetDLList(myList);
	int i;
	for (i = 0; i < DLListLength(myList) ; i++) {
		printf("Current val is %s\n", DLListCurrent(myList));
		moveNextDLList(myList);
	}

	return 0;
}

// testList.c - testing DLList data type
// Written by Ashesh Mahidadia, December 2017

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "DLList.h"

int main(int argc, char *argv[])
{
	int val = 0; 	

	DLList myList = newDLList();
	DLListAfter( myList, 34);
	DLListAfter( myList, 10);
	DLListAfter( myList, 52);
	DLListAfter( myList, 23);
	DLListAfter( myList, 5);

	showDLList(myList);

	val = DLListCurrent(myList); 
	printf("Current val is %d\n", val);

	printf("Moving to position 2\n");
	DLListMoveTo(myList, 2 );
	val = DLListCurrent(myList); 
	printf("Current val is %d\n", val);

	printf("Deleting current value\n");
	DLListDelete(myList);
	showDLList(myList);


	return 0;
}

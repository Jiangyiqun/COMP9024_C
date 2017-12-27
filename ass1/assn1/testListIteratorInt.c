/*
  client to test listIteratorInt.
  Written by Ashesh Mahidadia, Dec 2017
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "listIteratorInt.h"

char *myitoa(int *i){
  char *str;
  if(i == NULL){ return "NULL";}
  
  if ((str = malloc(20*sizeof(char))) == NULL) { return "Error";}
  sprintf(str, "%d", *i);
  return str;
}

/* ------ Helper functions for Operations on ADT ---------
*/

void adddsp(IteratorInt it, int v){
  int result = add(it , v); 
  printf("add %d, returns %d \n", v, result );
   
}
void nextdsp(IteratorInt it){
  printf("next, returns %s \n", myitoa(next(it)) ) ;   
}
void prevdsp(IteratorInt it){
  printf("previous, returns %s \n", myitoa(previous(it)) );   
}
void deletedsp(IteratorInt it){
  printf("delete, returns %d \n", deleteElm(it)) ;   
}

/*  You may need to add other Helper functions ! 
    ------ End of Helper functions for Operations on ADT -------
*/

int main(int argc, char *argv[]) {
  
	  /* The following code, may or may not be correct!
	     It's provided in case you find it difficult to understand 
	     how to test your list iterator.
	     The code below only tests basic operations, however 
	     make sure that you do test all the required functions properly in
	     your test file. 
	  */
	  
	  IteratorInt it = IteratorIntNew();
	  int TestNo = 0;

	  assert(argc > 1);
	  sscanf(argv[1], "%d", &TestNo);
	  
	  if(TestNo == 1) { 
			adddsp(it, 25);
			adddsp(it, 14);
			adddsp(it, 32);
			adddsp(it, 53);
			adddsp(it, 8);
	    prevdsp(it);
	    prevdsp(it);
	    prevdsp(it);
	  } else if(TestNo == 2) {
			adddsp(it, 25);
			adddsp(it, 14);
			adddsp(it, 32);
			adddsp(it, 53);
			adddsp(it, 8);
	    prevdsp(it);
	    prevdsp(it);
	    prevdsp(it);   
	    nextdsp(it);
	    nextdsp(it);
	  } else if(TestNo == 3) { 
			adddsp(it, 25);
			adddsp(it, 14);
			adddsp(it, 32);
			adddsp(it, 53);
			adddsp(it, 8);
	    prevdsp(it);
	    prevdsp(it);
	    prevdsp(it);
	    deletedsp(it);
	    nextdsp(it);
	    prevdsp(it);
	    prevdsp(it);
	  }


  	return EXIT_SUCCESS;
}

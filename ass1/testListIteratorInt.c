/*
  client to test listIteratorInt.
  Written by Ashesh Mahidadia, Dec 2017
  Moded by Jack Jiang, Jan 2018
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
void hasnextdsp(IteratorInt it){
  printf("hasnext, returns %d \n", hasNext(it) ) ;   
}
void hasprevdsp(IteratorInt it){
  printf("hasprev, returns %d \n", hasPrevious(it) ) ;   
}
void resetdsp(IteratorInt it){
  reset(it);
  printf("reset\n") ;   
}
void findnextdsp(IteratorInt it, int v){
  printf("findnext %d, returns %s \n", v, myitoa(findNext(it, v)) ) ;   
}
void findprevdsp(IteratorInt it, int v){
  printf("findprev %d, returns %s \n", v, myitoa(findPrevious(it, v)) ) ;   
}
void setdsp(IteratorInt it, int v){
  printf("set %d, returns %d \n", v, set(it, v)) ;   
}
void freedsp(IteratorInt it){
  freeIt(it);
  printf("free\n") ;   
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
      prevdsp(it);
      prevdsp(it);
      prevdsp(it);   
      nextdsp(it);
      nextdsp(it);
      nextdsp(it);
      nextdsp(it);
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
    } else if (TestNo == 4) {
      adddsp(it, 25);
      adddsp(it, 14);
      adddsp(it, 32);
      nextdsp(it);
      nextdsp(it);
      prevdsp(it);
      prevdsp(it);
      prevdsp(it);
      prevdsp(it);
      nextdsp(it);
      nextdsp(it);
      nextdsp(it);
      nextdsp(it);
    } else if (TestNo == 5) {
      nextdsp(it);
      prevdsp(it);
      deletedsp(it);
      deletedsp(it);
    } else if (TestNo == 6) {
      adddsp(it, 25);
      adddsp(it, 14);
      adddsp(it, 32);
      adddsp(it, 53);
      adddsp(it, 8);
      deletedsp(it);
      deletedsp(it);
      prevdsp(it);
      prevdsp(it);
      deletedsp(it);
      nextdsp(it);
      nextdsp(it);
      deletedsp(it);
    } else if (TestNo == 7) {
      adddsp(it, 25);
      adddsp(it, 14);
      adddsp(it, 32);
      hasnextdsp(it);
      hasprevdsp(it);
      prevdsp(it);
      prevdsp(it);
      hasnextdsp(it);
      hasprevdsp(it);
      prevdsp(it);
      hasnextdsp(it);
      hasprevdsp(it);
    } else if (TestNo == 8) {
      adddsp(it, 25);
      adddsp(it, 14);
      adddsp(it, 32);
      resetdsp(it);
      hasprevdsp(it);
      nextdsp(it);
      nextdsp(it);
    } else if (TestNo == 9) {
      adddsp(it, 25);
      adddsp(it, 14);
      adddsp(it, 32);
      adddsp(it, 53);
      adddsp(it, 8);
      findnextdsp(it, 0);
      prevdsp(it);
      prevdsp(it);
      prevdsp(it);
      findnextdsp(it, 666);
      prevdsp(it);
      nextdsp(it);
      findnextdsp(it, 53);
      nextdsp(it);
      prevdsp(it);
      prevdsp(it);
    } else if (TestNo == 10) {
      adddsp(it, 25);
      adddsp(it, 14);
      adddsp(it, 32);
      adddsp(it, 53);
      adddsp(it, 8);
      findprevdsp(it, 14);
      prevdsp(it);
      prevdsp(it);
      findprevdsp(it, 32);
      nextdsp(it);
    } else if (TestNo == 11) {
      adddsp(it, 25);
      adddsp(it, 14);
      adddsp(it, 32);
      adddsp(it, 53);
      adddsp(it, 8);
      setdsp(it, 6);
      prevdsp(it);
      prevdsp(it);
      setdsp(it, -53);
      nextdsp(it);
      setdsp(it, 62);
      prevdsp(it);
      prevdsp(it);
    } else if (TestNo == 12) {
      // adddsp(it, 25);
      freedsp(it);
      it = NULL;
      adddsp(it, 25);
      nextdsp(it);
      prevdsp(it);
      deletedsp(it);
      hasnextdsp(it);
      hasprevdsp(it);
      resetdsp(it);
      findnextdsp(it, 25);
      findprevdsp(it, 3);
      setdsp(it, 5);
      freedsp(it);
      it = NULL;
    } else if (TestNo == 13) {
      adddsp(it, 25);
      adddsp(it, 14);
      adddsp(it, 32);
      adddsp(it, 53);
      adddsp(it, 8);
      deletedsp(it);
      nextdsp(it);
      deletedsp(it);
      prevdsp(it);
      deletedsp(it);
      hasnextdsp(it);
      deletedsp(it);
      hasprevdsp(it);
      deletedsp(it);
      resetdsp(it);
      deletedsp(it);
      findnextdsp(it, 25);
      deletedsp(it);
      findprevdsp(it, 3);
      deletedsp(it);
      setdsp(it, 5);
      deletedsp(it);
      resetdsp(it);
      nextdsp(it);
      nextdsp(it);
      nextdsp(it);
      nextdsp(it);
      nextdsp(it);
    } else if (TestNo == 14) {
      adddsp(it, 25);
      adddsp(it, 14);
      adddsp(it, 32);
      adddsp(it, 53);
      adddsp(it, 8);
      setdsp(it, 5);
      nextdsp(it);
      setdsp(it, 5);
      prevdsp(it);
      setdsp(it, 5);
      hasnextdsp(it);
      setdsp(it, 5);
      hasprevdsp(it);
      setdsp(it, 5);
      resetdsp(it);
      setdsp(it, 5);
      findnextdsp(it, 25);
      setdsp(it, 5);
      findprevdsp(it, 3);
      setdsp(it, 5);
      resetdsp(it);
      nextdsp(it);
      nextdsp(it);
      nextdsp(it);
      nextdsp(it);
      nextdsp(it);
    } else if (TestNo == 15) {

    }
    return EXIT_SUCCESS;
}

/*
  listIteratorInt.c : list Iterator ADT implementation
  Written by .... 
  Date: ....
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "listIteratorInt.h"

typedef struct Node {
  int value;
  struct Node *prev;
  struct Node *next;
} Node;

typedef struct IteratorIntRep {
  Node *cursor;
  Node *first;
  Node *last;  
  int nitems;   // number of items, cursor is excluded
  int lcom;     // last command, 1: next; -1: prev; 0: NULL
} IteratorIntRep;


// private function
Node *newNode(int it)
{
  Node *new = malloc(sizeof(Node));
  assert(new != NULL);
  new->value = it;
  new->prev = NULL;
  new->next = NULL;
  return new;
}


// ADT implementation
IteratorInt IteratorIntNew(){
  struct IteratorIntRep *it = malloc(sizeof(struct IteratorIntRep));
  assert(it != NULL);
  Node *cursorNode = newNode(0);  // the value of cursor is meaningless
  it->cursor = cursorNode;
  it->first = cursorNode;
  it->last = cursorNode;
  it->nitems = 0;
  it->lcom = 0;  // last command, 1: next; -1: prev; 0: NULL
  return it;
}

void reset(IteratorInt it){

  // implement this function 

}


int add(IteratorInt it, int v){
  assert(it != NULL);
  Node *new = newNode(v);
  if (it->cursor == it->first) {
    // ^
    // new(become first) ^
    new->next = it->cursor;
    it->cursor->prev = new;
    it->first = new;
  } else {
    // before ^
    // before new ^
    Node *before = it->cursor->prev;
    before->next = new;
    new->prev = before;
    new->next = it->cursor;
    it->cursor->prev = new;
  }
  it->nitems++;
  it->lcom = 0;
  return 1;
}


int hasNext(IteratorInt it){
  
  // implement this function 
  
  return 0;  // you need to change this...
}

int hasPrevious(IteratorInt it){
  
  // implement this function 
  
  return 0;  // you need to change this...
}


int *next(IteratorInt it){
  assert(it != NULL);
  if (it->cursor == it->last) {
    // sth ^
    return NULL;
  } else if (it->cursor == it->first) {
    // ^ before after
    // before(become the first) ^ after
    Node *before = it->cursor->next;
    Node *after = before->next;
    it->first = before;
    before->next = it->cursor;
    it->cursor->prev = before;
    it->cursor->next = after;
    after->prev = it->cursor;
    if (after->next == NULL) {
      it->last = after;
    }
    it->lcom = 1;
    return &(before->value);
  } else {
    // bbefore ^ before after
    // bbefore before ^ after
    Node *bbefore = it->cursor->prev;
    Node *before = it->cursor->next;
    Node *after = before->next;
    bbefore->next = before;
    before->prev = bbefore;
    before->next = it->cursor;
    it->cursor->prev = before;
    it->cursor->next = after;
    after->prev = it->cursor;
    if (after->next == NULL) {
      it->last = after;
    }
    it->lcom = 1;
    return &(before->value);
  }
}

int *previous(IteratorInt it){
  assert(it != NULL);
  if (it->cursor == it->first) {
    return NULL;
  } else if (it->cursor == it->last) {
    // before after ^
    // before ^ after(become the last)
    Node *after = it->cursor->prev;
    Node *before = after->prev;
    before->next = it->cursor;
    it->cursor->prev = before;
    it->cursor->next = after;
    after->prev = it->cursor;
    it->last = after;
    if (before->prev == NULL) {
      it->first = before;
    }
    it->lcom = -1;
    return &(after->value);
  } else {
    // before after ^ aafter
    // before ^ after aafter
    Node *after = it->cursor->prev;
    Node *before = after->prev;
    Node *aafter = it->cursor->next;
    before->next = it->cursor;
    it->cursor->prev = before;
    it->cursor->next = after;
    after->prev = it->cursor;
    after->next = aafter;
    aafter->prev = after;
    if (before->prev == NULL) {
      it->first = before;
    }
    it->lcom = -1;
    return &(after->value);
  }
}



int deleteElm(IteratorInt it){
  assert(it != NULL);
  if (it->lcom == 0) {
    return 0;
  } else if (it->lcom == 1) {
    // last command is next, then we need to delete before
    Node *before = it->cursor->prev;
    Node *after = it->cursor->next;
    if (before == it->first) {
      // before ^ after
      // ^(become the first) after
      it->first = it->cursor;
      it->cursor->next = after;
      after->prev = it->cursor;
      free(before);
    } else {
      // bbefore before ^ after
      // bbefore ^ after
      Node *bbefore = before->prev;
      bbefore->next = it->cursor;
      it->cursor->prev = bbefore;
      it->cursor->next = after;
      after->prev = it->cursor;
      free(before);
    }
  } else if (it->lcom == -1) {
    // last command is prev, then we need to delete after
    Node *before = it->cursor->prev;
    Node *after = it->cursor->next;
    if (after == it->last) {
      // before ^ after
      // before ^(become the last)
      before->next = it->cursor;
      it->cursor->prev = before;
      it->last = it->cursor;
      free(after);
    } else {
      // before ^ after aafter
      // before ^ aafter
      Node *aafter = after->next;
      before->next = it->cursor;
      it->cursor->prev = before;
      it->cursor->next = aafter;
      aafter->prev = it->cursor;
      free(after);
    }
  }
  return 1;
}


int set(IteratorInt it, int v){
  
  // implement this function 

  return 0;
}

int *findNext(IteratorInt it, int v){

  // implement this function 
  
  return 0;
}

int *findPrevious(IteratorInt it, int v){
  
  // implement this function 
  
  return 0;
}

void freeIt(IteratorInt it){

  // implement this function 
  
  return;

}






/*
    listIteratorInt.c : list Iterator ADT implementation
    Written by Jack Jiang(z5129432)
    Date: 2018-01-01
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
    // int nitems;     // number of items, cursor is included
    int lcom;         // last command, 1: next; -1: prev; 0: NULL
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
    Node *cursorNode = newNode(0);    // the value of cursor is meaningless
    it->cursor = cursorNode;
    it->first = cursorNode;
    it->last = cursorNode;
    // it->nitems = 1;  // include cursor
    it->lcom = 0;    // last command, 1: next; -1: prev; 0: NULL
    return it;
}

void reset(IteratorInt it){
    if (it != NULL) {
        if (it->cursor != it->first ) {
            // cursor is not the first, so before must exists
            // oldfirst ... before ^ after
            // ^ oldfirst ... before after
            Node *oldfirst = it->first;         //  can be before
            Node *before = it->cursor->prev;
            Node *after = it->cursor->next;     // can be Null
            it->cursor->prev = NULL;
            it->cursor->next = oldfirst;
            oldfirst->prev = it->cursor;
            before->next = after;
            if (after != NULL) {
                after->prev = before;
            }
            // generate new first and last
            it->first = it->cursor;
            if (it->last == it->cursor) {
                it->last = before;
            }
        }
        // else if cursor is already the first, then nothing need to be done
        it->lcom = 0;
    }
}


int add(IteratorInt it, int v){
   if (it == NULL) {
        return 0;
    }
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
    // it->nitems++;
    it->lcom = 0;
    return 1;
}


int hasNext(IteratorInt it){
   if (it == NULL) {
        return 0;
    }
    it->lcom = 0;
    return (it->cursor != it->last);
}

int hasPrevious(IteratorInt it){
   if (it == NULL) {
        return 0;
    }
    it->lcom = 0;
    return (it->cursor != it->first);
}


int *next(IteratorInt it){
    if (it == NULL) {
        return NULL;
    }
    if (it->cursor == it->last) {
        // cursor is the last element, then there will be no next
        // ^ (last)
        // no next element
        it->lcom = 0;
        return NULL;
    }
    // cursor is not the last element, then before must exists
    // bbefore ^ before after
    // bbefore before ^ after
    Node *before = it->cursor->next;
    Node *after = before->next;     // can be NULL
    Node *bbefore = it->cursor->prev;     // can be NULL
    if (bbefore != NULL) {
        bbefore->next = before;
    }
    before->prev = bbefore;
    before->next = it->cursor;
    it->cursor->prev = before;
    it->cursor->next = after;
    if (after != NULL) {
        after->prev = it->cursor;
    }

    // generate new first and last
    if (bbefore == NULL) {
        it->first = before;
    } else if (bbefore->prev == NULL) {
        it->first = bbefore;
    }
    if (after == NULL) {
        it->last = it->cursor;
    } else if (after->next == NULL) {
        it->last = after;
    }
    it->lcom = 1;
    return &(before->value);
}

int *previous(IteratorInt it){
   if (it == NULL) {
        return NULL;
    }
    if (it->cursor == it->first) {
        // cursor is the first element, then there will be no previous
        // ^(first)
        // no previous element
        it->lcom = 0;
        return NULL;
    }
    // cursor is not the first element, then after must exists
    // before after ^ aafter
    // before ^ after aafter
    Node *after = it->cursor->prev;
    Node *before = after->prev;     // can be NULL
    Node *aafter = it->cursor->next;    // can be NULL
    if (before != NULL) {
        before->next = it->cursor;
    }
    it->cursor->prev = before;
    it->cursor->next = after;
    after->prev = it->cursor;
    after->next = aafter;
    if (aafter != NULL) {
        aafter->prev = after;
    }
    // generate new first and last
    if (before == NULL) {
        it->first = it->cursor;
    } else if (before->prev == NULL) {
        it->first = before;
    }
    if (aafter == NULL) {
        it->last = after;
    } else if (aafter->next == NULL) {
        it->last = aafter;
    }
    it->lcom = -1;
    return &(after->value);
}



int deleteElm(IteratorInt it){
   if (it == NULL) {
        return 0;
    }
    if (it->lcom == 0) {
        return 0;
    }
    // if must have at least one node(other than cursor)
    // because if it has no node(other than cursor), lcom will be 0
    if (it->lcom == 1) {
        // last command is next, then we need to delete before
        Node *before = it->cursor->prev;
        Node *after = it->cursor->next;
        if (before == it->first) {
            // before ^ after
            // ^(become the first) after
            it->first = it->cursor;
            it->cursor->prev = NULL;
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
    } else {
        // last command is prev, then we need to delete after
        Node *before = it->cursor->prev;
        Node *after = it->cursor->next;
        if (after == it->last) {
            // before ^ after
            // before ^(become the last)
            before->next = it->cursor;
            it->cursor->prev = before;
            it->cursor->next = NULL;
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
    // it->nitems--;
    it->lcom = 0;
    return 1;
}


int set(IteratorInt it, int v){
   if (it == NULL) {
        return 0;
    }
    if (it->lcom == 0) {
        return 0;
    }
    if (it->lcom == 1) {
        // last command is next, then before must exists
        // before ^
        it->cursor->prev->value = v;
    } else {
        it->cursor->next->value = v;
    }
    it->lcom = 0;
    return 1;
}

int *findNext(IteratorInt it, int v){
   if (it == NULL) {
        return NULL;
    }
    int nmove = 0; // number of moves
    while (it->cursor != it->last) {
        int *n = next(it);
        if (*n == v) {
            it->lcom = 1;
            return n;
        }
        nmove++;
    }
    for (; nmove > 0; nmove-- ) {
        previous(it);
    }
    it->lcom = 0;
    return NULL;
}

int *findPrevious(IteratorInt it, int v){
   if (it == NULL) {
        return NULL;
    }
    int nmove = 0; // number of moves
    while (it->cursor != it->first) {
        int *n = previous(it);
        if (*n == v) {
            it->lcom = -1;
            return n;
        }
        nmove++;
    }
    for (; nmove > 0; nmove-- ) {
        next(it);
    }
    it->lcom = 0;
    return NULL;
}

void freeIt(IteratorInt it){
    if (it != NULL) {
        // A        B       C        D       E...
        //FreeNow  FreeNext
        Node *freeNow = it->first;
        Node *freeNext;
        while (freeNext != NULL) {
        // freeNext is NULL means that in last loop, freeNow is it->last
            freeNext = freeNow->next;
            free(freeNow);
            freeNow = freeNext;
        }
        free(it);
    }
}



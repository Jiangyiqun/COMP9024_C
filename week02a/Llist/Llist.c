#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Llist.h"

typedef struct node {
   int data;
   struct node *next;
} NodeT;

NodeT *makeNode(int v) {
   NodeT *new = malloc(sizeof(NodeT));
   assert(new != NULL);
   new->data = v;       // initialise data
   new->next = NULL;    // initialise link to next node
   return new;          // return pointer to new node
}

void freeLL(NodeT *list) {
   NodeT *p;

   p = list;
   while (p != NULL) {
      NodeT *temp = p->next;
      free(p);
      p = temp;
   }
}

void showLL(NodeT *list) {
   NodeT *p;
   for (p = list; p != NULL; p = p->next)
      printf("%6d", p->data);
}

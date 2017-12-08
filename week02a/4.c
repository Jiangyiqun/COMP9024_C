// Author: Jack Jiang 
// Email: z5129432@student.unsw.edu.au
// Date: 2 Dec 2017
/* for COMP9024
(Dynamic stacks and queues)

1,    Describe in words how you would implement a queue ADT using a dynamic linked list. Which of the functions for the linked list implementation of a stack from the lecture need to be changed, and how?

StackPush, push in reversed order


2,    Suppose that you have a stack S containing n elements and a queue Q that is initially empty. Describe how you can use Q to scan S in order to check if it contains a certain element x, with the additional constraint that your algorithm must return the elements back to S in their original order. You should not use an additional array or linked list — only use S and Q.

S - n
Q - empty

flag = 0
for (i = 0, i < n, i++) {
	n = pop(S);
	if (n = x) {
		flag = 1;	
	}		
	Enqueue(n)
}

for (i = 0, i < n, i++) {
	push(dequeue(Q));
}

for (i = 0, i < n, i++) {
	enqueue(pop(S));
}

for (i = 0, i < n, i++) {
	push(dequeue(Q));
}
return flag;
*/

#include <stdlib.h>
#include <assert.h>
#include "stack.h"

typedef struct node {
   int data;
   struct node *next;
} NodeT;

typedef struct StackRep {
   int    height;   // #elements on stack
   NodeT *top;      // ptr to first element
} StackRep;

// set up empty stack
stack newStack() {
   stack S = malloc(sizeof(StackRep));     
   S->height = 0;
   S->top = NULL;
   return S;
}

// remove unwanted stack
void dropStack(stack S) {
   NodeT *curr = S->top;
   while (curr != NULL) {  // free the list
      NodeT *temp = curr->next;
      free(curr);
      curr = temp;
   }
   free(S);           // free the stack rep
}


// check whether stack is empty
int StackIsEmpty(stack S) {
   return (S->height == 0);
}

// insert an int on top of stack
void StackPush(stack S, int v) {
   NodeT *new = malloc(sizeof(NodeT));  
   assert(new != NULL);
   new->data = v;
   // insert new element at top
   new->next = S->top;
   S->top = new;
   S->height++;
}

// remove int from top of stack
int StackPop(stack S) {
   assert(S->height > 0);
   NodeT *head = S->top;
   // second list element becomes new top
   S->top = S->top->next;
   S->height--;
   // read data off first element, then free
   int d = head->data;
   free(head);
   return d;
}


// Queue ADO implementation ... COMP9024 17s2

#include "IntQueue.h"
#include <assert.h>

#define MAXITEMS 10

static struct {
   char item[MAXITEMS];
   int  top;
} QueueObject;  // defines the Data Object

void QueueInit() {         // set up empty Queue
   QueueObject.top = -1;
}

int QueueIsEmpty() {       // check whether Queue is empty
   return (QueueObject.top < 0);
}

void QueuePush(int ch) {  // insert char on top of Queue
   assert(QueueObject.top < MAXITEMS-1);
   QueueObject.top++;
   int i = QueueObject.top;
   QueueObject.item[i] = ch;
}

int QueuePop() {         // remove char from top of Queue
   assert(QueueObject.top > -1);
   int ch = QueueObject.item[0];
   QueueObject.top--;
   return ch;
}


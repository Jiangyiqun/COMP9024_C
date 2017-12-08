#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

typedef struct node {
   int data;
   struct node *next;
} NodeT;
NodeT *makeNode(int v);
void freeLL(NodeT *list);
void showLL(NodeT *list);
NodeT *joinLL(NodeT *head1, NodeT *head2);

int main(void) {
      char n[50];
      NodeT* all = NULL;
      NodeT* new = NULL;

      printf("Enter an integer: ");
      scanf("%s", n);   
      if (atoi(n) || (strlen(n) == 1 && n[0] == '0')) {                // if there is at least one integer
            all = makeNode(atoi(n));
            printf("Enter an integer: ");
            scanf("%s", n);   
            while (atoi(n) || (strlen(n) == 1 && n[0] == '0')) {
                  new = makeNode(atoi(n));
                  all = joinLL(all, new);
                  // printf("%d\n", atoi(n));
                  printf("Enter an integer: ");
                  scanf("%s", n);
            }
            printf("Finished.");
            showLL(all);
      } else {                      // if there nis no integer
            printf("Finished.");
      }
      freeLL(all);
      return EXIT_SUCCESS;
}

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
   NodeT *p = list;
   printf("List is %d", p->data);
   for (p = list->next; p != NULL; p = p->next) {
      printf("->%d", p->data);
   }
   printf("\n");
}

NodeT *joinLL(NodeT *head1, NodeT *head2) {
      NodeT *p = head1;
      while (p->next != NULL) {
            p = p->next;
      }
      p->next = head2;
      return head1;
}
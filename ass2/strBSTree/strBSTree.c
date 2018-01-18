// File: strBSTree.c
// Author: Jack Jiang (z5129432)
// Data: 2018x1
// Description:
//     BST implement of string
// Reference:
//      https://webcms3.cse.unsw.edu.au/COMP9024/18x1/resources/13854

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "strBSTree.h"
#include "strDlList.h"
#include "lengthDefine.h"


typedef struct Node {
   char data[MAX_WORD_LENGTH];
   DLList urlList;
   Tree left, right;
} Node;

// make a new node containing data
Tree newNode(char* it, char* url) {
   Tree new = malloc(sizeof(Node));
   assert(new != NULL);
   strcpy(new->data, it);
   new->urlList = newDLList();  // create a new DLList
   DLListAfter(new->urlList, url);   // add url to current DLList
   new->left = new->right = NULL;
   return new;
}

// create a new empty Tree
Tree newTree() {
   return NULL;
}

// free memory associated with Tree
void freeTree(Tree t) {
   if (t != NULL) {
      freeTree(t->left);
      freeTree(t->right);
      freeDLList(t->urlList);
      free(t);
   }
}

// display Tree sideways
void showTreeR(Tree t, int depth) {
   if (t != NULL) {
      showTreeR(t->left, depth+1);
      printf("%s  ", t->data);
      showDLListWithoutComma(t->urlList);
      showTreeR(t->right, depth+1);
   }
}

void showTree(Tree t) {
   showTreeR(t, 0);
}


// print Tree sideways
void printTreeR(Tree t, FILE *Index, int depth) {
   if (t != NULL) {
      printTreeR(t->left, Index, depth+1);
      fprintf(Index, "%s  ", t->data);
      printDLList(t->urlList, Index);
      printTreeR(t->right, Index, depth+1);
   }
}

void printTree(Tree t, FILE *Index) {
   printTreeR(t, Index, 0);
}

// insert a new item into a Tree
Tree TreeInsert(Tree t, char* it, char* url) {
   if (t == NULL)
      t = newNode(it, url);
   else if (strcmp(it, t->data) < 0 )           // it is less than current node
      t->left = TreeInsert(t->left, it, url);    // insert into left
   else if (strcmp(it, t->data) > 0)            // it is large than current node
      t->right = TreeInsert(t->right, it, url);      // insert into right
   else                                         // if they are the same
      DLListAdd(t->urlList, url);   // add url to current DLList without duplicate
   return t;
}



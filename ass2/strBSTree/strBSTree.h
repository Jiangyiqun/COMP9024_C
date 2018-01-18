// File: strBSTree.h
// Author: Jack Jiang (z5129432)
// Data: 2018x1
// Description:
//     BST header of string
// Reference:
//      https://webcms3.cse.unsw.edu.au/COMP9024/18x1/resources/13854

#include <stdbool.h>

typedef struct Node *Tree;

Tree newTree();        // create an empty Tree
void freeTree(Tree);   // free memory associated with Tree
void showTree(Tree);   // display a Tree (sideways)
Tree TreeInsert(Tree t, char* it, char* url);   // insert a new item into a Tree
void printTree(Tree t, FILE *Index); // print tree


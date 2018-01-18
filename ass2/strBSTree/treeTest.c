// Binary Search Tree ADT Tester ... COMP9024 17s2

#include <stdlib.h>
#include <stdio.h>
#include "BSTree.h"

int main(void) {
    Tree mytree = newTree();
    TreeInsert(mytree, 4);
    TreeInsert(mytree, 5);
    TreeInsert(mytree, 1);
    TreeInsert(mytree, 64);
    TreeInsert(mytree, 9);
    TreeInsert(mytree, 12);
    TreeInsert(mytree, 5);
    TreeInsert(mytree, 7);
    showTree(mytree);
    freeTree(mytree);
    return EXIT_SUCCESS;
}

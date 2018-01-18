// Binary Search Tree ADT Tester ... COMP9024 17s2

#include <stdlib.h>
#include <stdio.h>
#include "strBSTree.h"

int main(void) {
    Tree mytree = newTree();
    mytree = TreeInsert(mytree, "max", "url21");
    mytree = TreeInsert(mytree, "action", "url21");
    mytree = TreeInsert(mytree, "biubiubiu", "url32");
    mytree = TreeInsert(mytree, "max", "url32");
    mytree = TreeInsert(mytree, "zoo", "url21");   
    mytree = TreeInsert(mytree, "good", "url44");
    showTree(mytree);
    freeTree(mytree);
    return EXIT_SUCCESS;
}

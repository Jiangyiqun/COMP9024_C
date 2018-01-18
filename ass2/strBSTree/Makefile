treeTest : treeTest.o strBSTree.o
	gcc -o treeTest treeTest.o strBSTree.o

treeTest.o : treeTest.c strBSTree.h
	gcc -Wall -Werror -c treeTest.c

strBSTree.o : strBSTree.c strBSTree.h
	gcc -Wall -Werror -c strBSTree.c

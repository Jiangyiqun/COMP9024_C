treeTest : treeTest.o strBSTree.o strDlList.o
	gcc -o treeTest treeTest.o strBSTree.o

treeTest.o : treeTest.c strBSTree.h strDlList.h
	gcc -Wall -Werror -c treeTest.c

strBSTree.o : strBSTree.c strBSTree.h strDlList.h
	gcc -Wall -Werror -c strBSTree.c
	
strDlList.o : strDlList.c strDlList.h

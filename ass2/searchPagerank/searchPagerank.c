// File: searchPagerank.c
// Author: Jack Jiang (z5129432)
// Data: 2018x1
// Description:
//     for COMP9024 Assignment 2
// Reference:
//     https://www.cse.unsw.edu.au/~cs9024/18x1/assn/assn2/Ass2.html

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include "strDlList.h"
#include "searchPagerank.h"

#define MAX_URL_LENGTH 6    // 5 char plus a terminator
#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 1000

int main(int argc, char* argv[]) {
    DLList indexList = readInvertedIndex();
    // showDLList(indexList);
    // remove unmatched URLs using invertedIndex.txt
    if (argc > 1) {
        char line[MAX_LINE_LENGTH];
        FILE *txt = fopen("invertedIndex.txt", "r");
        int i;  // index for keyword (argv[])
        int j;  // index ofr indexList
        int length; // indexList's length

        while (fgets(line, MAX_LINE_LENGTH, txt) != NULL) {
            // in every line of invertedIndex, search each input keyword
            for (i = 1; i < argc; i++) {
                if (strstr(line, argv[i]) != NULL) {
                    // in every line including a keyword, scan for each URL in indexList
                    resetDLList(indexList);
                    length = DLListLength(indexList);
                    for (j = 0; j < length; j++) {
                        // if url is not in the line, then delete this url
                        if (strstr(line, DLListCurrent(indexList)) == NULL) {
                            DLListDelete(indexList);
                        } else {
                            moveNextDLList(indexList);
                        }
	                }
                }
            }
        }
        fclose(txt);
    }
    showInvertedIndex(indexList, 30);
    freeDLList(indexList);
    return EXIT_SUCCESS;
}


DLList readInvertedIndex() {
    DLList indexList = newDLList();
    char line[MAX_LINE_LENGTH];
    FILE *txt = fopen("pagerankList.txt", "r");

    while (fgets(line, MAX_LINE_LENGTH, txt) != NULL) {
        DLListAfter(indexList, strtok(line, ", "));
    }
    fclose(txt);
    return indexList;
}


void showInvertedIndex(DLList indexList, int maxLine) {
    int i;

    resetDLList(indexList);
	for (i = 0; (i < DLListLength(indexList)) && (i < maxLine); i++) {
		printf("%s\n", DLListCurrent(indexList));
		moveNextDLList(indexList);
	}
}
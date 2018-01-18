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
#include "lengthDefine.h"

#define RESULT_MAX_LINE 30

int main(int argc, char* argv[]) {
    DLList indexList = readInvertedIndex();
    int keyLeft = argc - 1; // the number of keywords that need to be found in index
    // showDLList(indexList);
    // remove unmatched URLs using invertedIndex.txt
    if (argc > 1) {
        char line[MAX_LINE_LENGTH];
        FILE *txt = fopen("invertedIndex.txt", "r");
        int i;  // index for keyword (argv[])
        int j;  // index ofr indexList
        int length; // indexList's length
        
        // read "invertedIndex.txt" line by line
        while (fgets(line, MAX_LINE_LENGTH, txt) != NULL) {
            // in every line of invertedIndex, search for each input keywords
            for (i = 1; i < argc; i++) {
                if (strstr(line, argv[i]) != NULL) {
                    keyLeft--;  // a keyword has been found
                    // in every line including a keyword, search for each URL in indexList
                    resetDLList(indexList);
                    length = DLListLength(indexList);
                    for (j = 0; j < length; j++) {
                        // if every URL in indexList is not in the line
                        // This mean that this URL doesn't include any of keywords
                        // then we delete this url in indexList
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
    // only show the result when all keyword has been found in index
    if (keyLeft == 0) { 
        showInvertedIndex(indexList);
    }  
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


void showInvertedIndex(DLList indexList) {
    int i;

    resetDLList(indexList);
	for (i = 0; (i < DLListLength(indexList)) && (i < RESULT_MAX_LINE); i++) {
		printf("%s\n", DLListCurrent(indexList));
		moveNextDLList(indexList);
	}
}

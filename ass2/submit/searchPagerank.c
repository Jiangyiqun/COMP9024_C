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
#include "lengthDefine.h"
#include "searchPagerank.h"

#define RESULT_MAX_LINE 30

int main(int argc, char* argv[]) {
    int nURL = getNumberOfURL();
    indexList* myList = readInvertedIndex(nURL);
    // showInvertedIndex(myList, nURL);
    // scan keywords and invertedIndex.txt
    if (argc > 1) {
        char line[MAX_LINE_LENGTH];
        FILE *txt = fopen("invertedIndex.txt", "r");
        int i;  // index for keyword (argv[])
        int j;  // index for indexList
        char keyword[MAX_URL_LENGTH + 1];
        
        // read "invertedIndex.txt" line by line
        while (fgets(line, MAX_LINE_LENGTH, txt) != NULL) {
            // in every line of invertedIndex, search for each input keywords
            for (i = 1; i < argc; i++) {
                strcpy(keyword, argv[i]);
                strcat(keyword, " ");
                if (strstr(line, keyword) != NULL) {
                    // in each line contains keyword, search for URLs that in myList
                    for (j = 0; j < nURL; j++) {
                        if (strstr(line, myList[j].URL) != NULL) {
                            // printf("%s %s\n", argv[i], myList[j].URL);
                            myList[j].PR += 1;  // add PR by 1 is URL is in list
                        }
                    }
                }
            }
        }
        fclose(txt);
    }
    myList = sortInvertedIndex(myList, nURL);
    showInvertedIndex(myList, nURL);
    free(myList);
    return EXIT_SUCCESS;
}


int getNumberOfURL() {
    int nURL = 0;
    char line[MAX_LINE_LENGTH];
    FILE *txt = fopen("pagerankList.txt", "r");
    while (fgets(line, MAX_LINE_LENGTH, txt) != NULL) {
        nURL++;
    }
    fclose(txt);
    return nURL;
}


indexList* readInvertedIndex(int nURL) {
    indexList* myList = malloc(sizeof(indexList) * nURL);
    int i = 0;
    char line[MAX_LINE_LENGTH];
    FILE *txt = fopen("pagerankList.txt", "r");
    while (fgets(line, MAX_LINE_LENGTH, txt) != NULL) {
        strcpy(myList[i].URL, strtok(line, ", "));
        strtok(NULL, ", ");
        myList[i].PR = atof(strtok(NULL, ", "));
        i++;
    }
    fclose(txt);
    return myList;
}


void showInvertedIndex(indexList* myList, int nURL) {
    int i;

	for (i = 0; (i < nURL) && (i < RESULT_MAX_LINE); i++) {
    	//printf("%s, %.7f\n", myList[i].URL, myList[i].PR);
	    if (myList[i].PR >= 1.0 ) {
	    	//printf("%s, %.7f\n", myList[i].URL, myList[i].PR);
		    printf("%s\n", myList[i].URL);
	    }
	}
}


indexList* sortInvertedIndex(indexList* myList, int nURL) {
    int i;
    indexList temp;
    int hasChange = 1;
    while (hasChange == 1) {
        hasChange = 0;
        for(i = 1; i < nURL; i++) {
            if(myList[i - 1].PR < myList[i].PR) {
                hasChange = 1;
                temp.PR = myList[i - 1].PR;
                myList[i - 1].PR = myList[i].PR;
                myList[i].PR = temp.PR;
                strcpy(temp.URL, myList[i - 1].URL);
                strcpy(myList[i - 1].URL, myList[i].URL);
                strcpy(myList[i].URL, temp.URL);
            }
         }
    }
    return myList;
}

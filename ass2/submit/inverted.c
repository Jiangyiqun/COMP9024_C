// File: inverted.c
// Author: Jack Jiang (z5129432)
// Data: 2018x1
// Description:
//     for COMP9024 Assignment 2
// Reference:
//     https://www.cse.unsw.edu.au/~cs9024/18x1/assn/assn2/Ass2.html

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>
#include"strBSTree.h"
#include"inverted.h"
#include"lengthDefine.h"

int main(void) {
    int nURL = getURLNumber();
    char *URLList = createURLList(nURL);
    Tree URLIndex = newTree();
    URLIndex = readIndex(URLIndex, URLList, nURL);
    writeIndex(URLIndex);
    free(URLList);
    freeTree(URLIndex);
    return EXIT_SUCCESS;
}


int getURLNumber() {
    int nURL = 0;
    char url[MAX_URL_LENGTH];
    FILE *collection = fopen("collection.txt", "r");
    while (fscanf(collection, "%s", url) != EOF) {
        nURL++;
    }
    fclose(collection);
    return nURL;
}


char *createURLList(int nURL) {
    char url[MAX_URL_LENGTH];
    int i;
    char *URLList = malloc(sizeof(char) * MAX_URL_LENGTH * nURL);
    assert(URLList != NULL);
    FILE *collection = fopen("collection.txt", "r");
    for (i = 0; fscanf(collection, "%s", url) != EOF; i ++) {
        strcpy(&URLList[i * MAX_URL_LENGTH], url);
    }
    fclose(collection);
    // debug
    // printf("The %d URLList is:\n", nURL);
    // for (i =0; i < nURL * MAX_URL_LENGTH; i += MAX_URL_LENGTH) {
    //     printf("    %s\n", &URLList[i]);
    // }
    return URLList;
}

Tree readIndex(Tree URLIndex, char *URLList, int nURL) {
    int i;
    char pageFile[MAX_URL_LENGTH + 4];  // filename such as "url11.txt"
    char extensionName[] = ".txt";
    FILE *urlFile;
    int hashEncountered;    // how many of hash symbol # has been already encountered

    char word[MAX_WORD_LENGTH];
    for (i = 0; i < nURL; i++) {
        //  generate the file name of urlxx.txt
        strcpy(pageFile, &URLList[i * MAX_URL_LENGTH]);
        strcat(pageFile, extensionName);
        // debug
        //printf("in file %s\n", pageFile);
        urlFile = fopen(pageFile, "r");
        hashEncountered = 0;
        while (fscanf(urlFile, "%s", word) != EOF) {
            if ( word[0] == '#') {
                hashEncountered++;
                if (hashEncountered == 3) {
                    fscanf(urlFile, "%s", word);     // drop the next word, which is Section-1
                } 
                if (hashEncountered == 4) {
                    break;                          // finish reading
                }
            } else {
                if (hashEncountered == 3){
                    // debug
                    //printf("%s\n", normalise(word));
                    //printf("insert %s and %s into tree\n", normalise(word), &URLList[i * MAX_URL_LENGTH]);
                    URLIndex = TreeInsert(URLIndex, normalise(word), &URLList[i * MAX_URL_LENGTH]);
                }
            }
        }
        fclose(urlFile);
    }
    return URLIndex;
}

char *normalise(char* word) {
    int i = 0; // index in word

    // converting all characters to lowercase
    while (word[i] != '\0') {
        word[i] = tolower(word[i]);
        i++;
    }
    
    // remove trailing punctuation, including:
    //      '.' (dot), ',' (comma), ';' (semicolon), ? (question mark)
    i--;    // reset i point to the last char, but not the terminator
    while (word[i] == '.' || word[i] == ',' 
           || word[i] == ';' || word[i] == '?') {
        word[i] = '\0';
        i--;
    }
    return word;
}

void writeIndex(Tree URLIndex) {
    FILE *Index = fopen("invertedIndex.txt", "w");
    printTree(URLIndex, Index);
    fclose(Index);
}

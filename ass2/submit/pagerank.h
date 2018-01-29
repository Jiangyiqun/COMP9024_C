// File: pagerank.h
// Author: Jack Jiang (z5129432)
// Data: 2018x1
// Description:
//     for COMP9024 Assignment 2
// Reference:
//     https://www.cse.unsw.edu.au/~cs9024/18x1/assn/assn2/Ass2.html

#ifndef PAGERANK_H
#define PAGERANK_H

#include "lengthDefine.h"

// a structure used to create PRList
typedef struct PRNode {
    char url[MAX_URL_LENGTH];
    int degree;
    float PR;
} PRNode;

// return the number of URLs in collection.txt
int getURLNumber();

// initialise an array of PRNode:
//      char url[5]: fill with urls in collection.txt
//      int degree: initialise to 0
//      float PR: initialise to o
// and then return the pointer to the array
PRNode* createPRList(int nURL);

// write to file pagerankList.txt, as following format
    // url31, 3, 0.2623546
    // url21, 1, 0.1843112
    // url34, 6, 0.1576851
    // url22, 4, 0.1520093
    // url32, 6, 0.0925755
    // url23, 4, 0.0776758
    // url11, 3, 0.0733884
int writePRList(PRNode *PRList, int nURL);

// generate a graph data structure
// return the pointer of the graph
Graph createGraph(PRNode *PRList, int nURL);

// return the index of a URL
int getURLIndex(char* url, PRNode *PRList, int nURL);

// generate degree and put them into PRList
int getOutDegree(Graph web, PRNode *PRList, int nURL);

// calculate pagerank and put them into PRList
int getPagerank(float d, float minDifferece, int maxIterations,
                Graph web, PRNode *PRList, int nURL);

// sort PRList in descending order of PR value
int sortPRList(PRNode *PRList, int nURL);

// just print the debug information on the screen
void showDebugInfo(float d, float minDifferece,int maxIterations,
                    PRNode *PRList, int nURL);

#endif

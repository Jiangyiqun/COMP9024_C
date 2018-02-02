// File: pagerank.c
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
#include"directedGraph.h"
#include"pagerank.h"
#include "lengthDefine.h"



int main(int argc, char *argv[]) {
    assert(argc == 4);
    float d = atof(argv[1]);
    float minDifferece = atof(argv[2]);
    int maxIterations = atoi(argv[3]);
    int nURL = getURLNumber();
    PRNode *PRList = createPRList(nURL);
    // showDebugInfo(d, minDifferece, maxIterations, PRList, nURL);
    Graph web = createGraph(PRList, nURL);
    // showGraph(web);

    getOutDegree(web, PRList, nURL);
    // showDebugInfo(d, minDifferece, maxIterations, PRList, nURL);
    getPagerank(d, minDifferece, maxIterations, web, PRList, nURL);
    // showDebugInfo(d, minDifferece, maxIterations, PRList, nURL);
    sortPRList(PRList, nURL);
    //showDebugInfo(d, minDifferece, maxIterations, PRList, nURL);
    writePRList(PRList, nURL);
    freeGraph(web);
    free(PRList);
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


PRNode *createPRList(int nURL) {
    char url[MAX_URL_LENGTH];
    int i;
    PRNode *PRList = malloc(sizeof(PRNode) * nURL);
    assert(PRList != NULL);
    FILE *collection = fopen("collection.txt", "r");
    for (i = 0; fscanf(collection, "%s", url) != EOF; i ++) {
        strcpy(PRList[i].url, url);
        PRList[i].degree = 0;
        PRList[i].PR = 0;
    }
    fclose(collection);
    return PRList;
}


int writePRList(PRNode *PRList, int nURL) {
    int i;
    FILE *pagerankList = fopen("pagerankList.txt", "w");
    for (i = 0; i < nURL; i++) {
        fprintf(pagerankList, "%s, %d, %.7f\n",
                PRList[i].url, PRList[i].degree, PRList[i].PR);
    }
    fclose(pagerankList);
    return 1;
}


Graph createGraph(PRNode *PRList, int nURL) {
    Graph web = newGraph(nURL);
    int i;
    char pageFile[MAX_URL_LENGTH + 4];  // filename such as "url11.txt"
    char extensionName[] = ".txt";
    FILE *pageData;
    int hashEncountered;    // how many of hash symbol # has been already encountered
    char url[MAX_URL_LENGTH];
    Edge link;  // edge to be added

    for (i = 0; i < nURL; i++) {
        //  generate the file name of urlxx.txt
        strcpy(pageFile, PRList[i].url);
        strcat(pageFile, extensionName);
        // debug
        // printf("reading file %s\n", pageFile);

        pageData = fopen(pageFile, "r");
        hashEncountered = 0;
        while (fscanf(pageData, "%s", url) != EOF) {
            if ( url[0] == '#') {
                hashEncountered++;
                if (hashEncountered == 1) {     // if this is the first hash
                    fscanf(pageData, "%s", url);    // drop next url(which is "Section-1" actually)
                }
                if (hashEncountered == 2) {     // if this is the second hash
                    break;                      // finish reading
                }
            } else {                            // insert edges
                // debug
                // printf("which includes URLs: %s\n", url);

                link.v = getURLIndex(PRList[i].url, PRList, nURL);  // source
                link.w = getURLIndex(url, PRList, nURL);    // destination
                insertEdge(web, link);
            }
        }
        fclose(pageData);
    }
    return web;
}


int getURLIndex(char* url, PRNode *PRList, int nURL) {
    int i;
    for (i = 0; i < nURL; i++) {
        if (strcmp(PRList[i].url, url) == 0) {
            break;
        }
    }
    return i;
}


int getOutDegree(Graph web, PRNode *PRList, int nURL) {
    int i;
    for (i = 0; i < nURL; i++) {
        PRList[i].degree = outDegree(web, i);
    }
    return 1;
}


int getPagerank(float d, float minDifferece, int maxIterations,
                Graph web, PRNode *PRList, int nURL) {
    float *newPR = malloc(sizeof(float) * nURL);    // PR used in calculation
    assert(newPR != NULL);
    float incomingPR = 0;   // PR from all incoming links, not random jump
    int v;          // URL need to generate PR
    int w;          // incoming url of v
    int iteration;  // iteration times
    float diff;
    float totalDiff;     // total diff


    // initialise PR
    for (v = 0; v < nURL; v++) {
        // must write 1.0 not 0; or the result will be integer
        PRList[v].PR = 1.0 / nURL;
        newPR[v] = 1.0 / nURL;
    }

    // calculate PR by iterations
    iteration = 0;
    totalDiff = minDifferece;
    while ((iteration < maxIterations)
            && (totalDiff >= minDifferece)) {
        iteration++;
        // calculate the PR and store it into newPR[]
        for (v = 0; v < nURL; v++) {
            // calculate incoming link PR of v
            incomingPR = 0;
            for (w = 0; w < nURL; w++) {
                if (adjacent(web, w, v)) {
                    incomingPR += PRList[w].PR / PRList[w].degree;
                }
            }
            // calculate the overall PR of v
            newPR[v] = ((1.0 - d) / nURL) + (d * incomingPR);
        }

        // calculate the total diff
        totalDiff = 0;
        for (v = 0; v < nURL; v++) {
            diff = PRList[v].PR - newPR[v];
            if (diff < 0) {
                diff = -diff;       // diff = abs(diff)
            }
            totalDiff += diff;
        }

        // copy newPR[] to PRList[].PR
        for (v = 0; v < nURL; v++) {
            PRList[v].PR = newPR[v];
        }
    }
    // debug
    //printf("this is the %d interation\n", iteration);
    //printf("the totalDiff is the %.7f\n", totalDiff);
    
    free(newPR);
    return 1;
}

int sortPRList(PRNode *PRList, int nURL) {
    int i;
    int swap = 1;   // 0: no swap occur in the loop; 1: swap occur in the loop
    PRNode temp;    // a temperory node for swap
    while (swap == 1) {
        swap = 0;   // mark as no swap occurs
        for (i = 1; i < nURL; i ++) {
            if (PRList[i-1].PR < PRList[i].PR) {
                swap = 1;   // mark as swap occurs
                strcpy(temp.url, PRList[i].url);
                temp.degree = PRList[i].degree;
                temp.PR = PRList[i].PR;
                strcpy(PRList[i].url, PRList[i-1].url);
                PRList[i].degree= PRList[i-1].degree;
                PRList[i].PR = PRList[i-1].PR;
                strcpy(PRList[i-1].url, temp.url);
                PRList[i-1].degree= temp.degree;
                PRList[i-1].PR = temp.PR;
            }
        }
    }
    return 1;
}


void showDebugInfo(float d, float minDifferece,
                    int maxIterations, PRNode *PRList, int nURL) {
    int i;
    float sum = 0;
    printf("Your input parameters are:\n");
    printf("    d = %.7f\n", d);
    printf("    minDifferece = %.7f\n", minDifferece);
    printf("    maxIterations = %d\n", maxIterations);
    printf("The number of URLs is: %d\n", nURL);
    printf("The content in PRList is:\n");
    for (i = 0; i < nURL; i++) {
        printf("    %s, %d, %.7f\n", PRList[i].url,
                PRList[i].degree, PRList[i].PR);
    }
    for (i = 0; i < nURL; i++) {
        sum += PRList[i].PR;
    }
    printf("The sum of pagerank is: %f\n", sum);
}

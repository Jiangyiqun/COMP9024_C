#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#include"directedGraph.h"   // modified from https://www.cse.unsw.edu.au/~cs9024/18x1/slides/week03a/progs/
#include"pagerank.h"

#define MAX_URL_LENGTH 6    // 5 char plus a terminator


int main(void) {
    float d = 0.85;
    float minDifferece = 0.00001;
    int maxIterations = 1000;

    int nURL = GetURLNumber();
    // printf("The number of URLs are: %d\n",nURL);
    PRNode *PRList = InitPRList(nURL);
    // showPRList(PRList, nURL);

    Graph web = GetGraph(PRList, nURL);
    // showGraph(web);
    GetOutDegree(web, PRList, nURL);
    // showPRList(PRList, nURL);
    GetPagerank(d, minDifferece, maxIterations, web, PRList, nURL);
    // showPRList(PRList, nURL);
    WritePRList(PRList, nURL);
    freeGraph(web);
    free(PRList);
    return EXIT_SUCCESS;
}


int GetURLNumber() {
    int nURL = 0;
    char url[MAX_URL_LENGTH];
    FILE *collection = fopen("collection.txt", "r");
    while (fscanf(collection, "%s", url) != EOF) {
        nURL++;
    }
    fclose(collection);
    return nURL;
}


PRNode *InitPRList(int nURL) {
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


int WritePRList(PRNode *PRList, int nURL) {
    int i;
    FILE *pagerankList = fopen("pagerankList.txt", "w");
    for (i = 0; i < nURL; i++) {
        fprintf(pagerankList, "%s, %d, %.7f\n", PRList[i].url, PRList[i].degree, PRList[i].PR);
    }
    fclose(pagerankList);
    return 1;
}


Graph GetGraph(PRNode *PRList, int nURL) {
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

                link.v = GetURLIndex(PRList[i].url, PRList, nURL);  // source
                link.w = GetURLIndex(url, PRList, nURL);    // destination
                insertEdge(web, link);
            }
        }
        fclose(pageData);
    }
    return web;
}


int GetURLIndex(char* url, PRNode *PRList, int nURL) {
    int i;
    for (i = 0; i < nURL; i++) {
        if (strcmp(PRList[i].url, url) == 0) {
            break;
        }
    }
    return i;
}


int GetOutDegree(Graph web, PRNode *PRList, int nURL) {
    int i;
    for (i = 0; i < nURL; i++) {
        PRList[i].degree = outDegree(web, i);
    }
    return 1;
}


void showPRList(PRNode *PRList, int nURL) {
    int i;
    for (i = 0; i < nURL; i++) {
        printf("%s, %d, %.7f\n", PRList[i].url, PRList[i].degree, PRList[i].PR);
    }
}


int GetPagerank(float d, float minDifferece, int maxIterations, Graph web, PRNode *PRList, int nURL) {
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
        PRList[v].PR = 1.0 / nURL;      // must write 1.0 not 0; or the result will be integer
        newPR[v] = 1.0 / nURL;
    }

    // calculate PR by iterations
    iteration = 0;
    totalDiff = minDifferece;
    while ((iteration < maxIterations) && (totalDiff >= minDifferece)) {
        iteration++;
        // calculate the PR and store it into newPR[]
        for (v = 0; v < nURL; v++) {
            // calculate incoming link PR of v
            incomingPR = 0;
            for (w = 0; w < nURL; w++) {
                if (adjacent(web, w, v)) {
                    incomingPR += PRList[w].PR / PRList[w].degree;
                }
            // calculate the overall PR of v
            newPR[v] = ((1.0 - d) / nURL) + (d * incomingPR);
            }
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
    // printf("this is the %d interation\n", iteration);
    // printf("the totalDiff is the %.7f\n", totalDiff);
    
    free(newPR);
    return 1;
}
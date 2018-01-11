#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Graph.h"   // from https://www.cse.unsw.edu.au/~cs9024/18x1/slides/week03a/progs/
#include"readData.h"    // from https://www.cse.unsw.edu.au/~cs9024/18x1/slides/week03a/progs/


int main(void) {
    int nURL = GetURLNumber();
    char *listOfURL = GetCollection(nURL);
    // int i;
    // printf("The number of URLs are: %d\nWhich are:\n",nURL);
    // for (i = 0; i < nURL; i++) {
    //     printf("%s\n", &listOfURL[i * 6]);
    // }
    Graph web = GetGraph(listOfURL, nURL);
    showGraph(web);
    // char *url = "url34";
    // printf("index of url34 is: %d\n", GetURLIndex(url, listOfURL, nURL));
    return EXIT_SUCCESS;
}

int GetURLNumber() {
    int nURL = 0;
    FILE *collection = fopen("collection.txt", "r");
    char url[6];
    while (fscanf(collection, "%s", url) != EOF) {
        nURL++;
    }
    fclose(collection);
    return nURL;
}

char* GetCollection(int nURL) {
    char *listOfURL = malloc(sizeof(char) * 6 * nURL);
    FILE *collection = fopen("collection.txt", "r");
    char url[6];
    int i;
    for (i = 0; fscanf(collection, "%s", url) != EOF; i += 6) {
        strcpy(&(listOfURL[i]), url);
    }
    fclose(collection);
    return listOfURL;
}

Graph GetGraph(char *listOfURL, int nURL) {
    Graph web = newGraph(nURL);
    int i;
    char url[50];
    char pageFile[] = "url00.txt";
    FILE *pageData;
    int hashNumber;
    Edge link;
    for (i = 0; i < nURL; i++) {
        pageFile[3] = listOfURL[i * 6 + 3];
        pageFile[4] = listOfURL[i * 6 + 4];
        // printf("now I'm reading %s\n", pageFile);
        pageData = fopen(pageFile, "r");
        hashNumber = 0;
        while (fscanf(pageData, "%s", url) != EOF) {
            if ( url[0] == '#') {
                hashNumber++;
                if (hashNumber == 1) {
                    fscanf(pageData, "%s", url);
                }
                if (hashNumber == 2) {
                    break;
                }
            } else {
                // source: &listOfURL[i * 6 ]
                // destination: url
                link.v = GetURLIndex(&listOfURL[i*6], listOfURL, nURL);
                link.w = GetURLIndex(url, listOfURL, nURL);
                insertEdge(web, link);
            }
        }
        fclose(pageData);
        // break;
    }
    return web;
}

int GetURLIndex(char* url, char *listOfURL, int nURL) {
    int i;
    for (i = 0; i < nURL; i++) {
        if (strcmp((&listOfURL[i * 6]), url) == 0) {
            break;
        }
    }
    return i;
}
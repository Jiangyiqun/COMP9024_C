#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Graph.h"

void assignID(Graph g, int nV, int *componentOf, int index, int componentID);

int main(void) {
    int nV = 9;  // number of vertices
    Edge e;     // an edge
    int i, j;  // index
    int componentID = 1;    //component ID, increase from 1
    int *componentOf = malloc(sizeof(int) * nV);     //array of component ID related to each vertix
    // // create new empty graph
    printf("Enter the number of vertices: ");
    scanf("%d", &nV);
    Graph g = newGraph(nV);
    // //insert edge into graph
    while (true) {
        printf("Enter an edge (from): ");
        if (scanf("%d", &(e.v)) == 0) {
            printf("Finished.\n");
            break;
        }
        printf("Enter an edge (to): ");
        if (scanf("%d", &(e.w)) == 0) {
            printf("Finished.\n");
            break;
        }
        insertEdge(g, e);
    }

   //debug codes
    // e.v = 0;
    // e.w = 1;
    // insertEdge(g, e);
    // e.v = 1;
    // e.w = 2;
    // insertEdge(g, e);
    // e.v = 4;
    // e.w = 3;
    // insertEdge(g, e);
    // e.v = 6;
    // e.w = 5;
    // insertEdge(g, e);
    // e.v = 6;
    // e.w = 7;
    // insertEdge(g, e);
    // e.v = 5;
    // e.w = 7;
    // insertEdge(g, e);
    // e.v = 5;
    // e.w = 8;
    // insertEdge(g, e);
    // e.v = 7;
    // e.w = 8;
    // insertEdge(g, e);
    // printf("\n");
    // showGraph(g);
    // printf("\n");

    //calculate number of compnent
    for (i = 0; i < nV; i++){
        componentOf[i] = -1;
    }
    for (i = 0; i < nV; i++){
        if (componentOf[i] == -1) {
            assignID(g, nV, componentOf, i, componentID);
            componentID++;
        }
    }


    // print the result
    printf("Number of connected components: %d\n", componentID - 1);
    for (i = 1; i < componentID; i++) {
        printf("Component %d:\n", i);
        for (j = 0; j < nV; j++) {
            if (componentOf[j] == i) {
                printf("%d\n", j);
            }
        }
    }
    free(componentOf);
    freeGraph(g);
    return EXIT_SUCCESS;
}

void assignID(Graph g, int nV, int *componentOf, int index, int componentID) {
    int i;
    componentOf[index] = componentID;          // assign an ID to current index
    for (i = 0; i < nV; i++) {
        if (adjacent(g, index, i)) {
            if (componentOf[i] == -1) {
                assignID(g, nV, componentOf, i, componentID);
            } 
        }
    }
}
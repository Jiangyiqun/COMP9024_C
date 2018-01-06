#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Graph.h"

int main(void) {
    int nV = 9;  // number of vertices
    Edge e;     // an edge
    int i;  // index of edges
    int *componentOf = malloc(sizeof(int) * nV);     //degree of an vertice
    for (i = 0; i < nV; i++){
        componentOf[i] = -1;
    }
    // // create new empty graph
    // printf("Enter the number of vertices: ");
    // scanf("%d", &nV);
    Graph g = newGraph(nV);
    // //insert edge into graph
    // while (true) {
    //     printf("Enter and edge (from): ");
    //     if (scanf("%d", &(e.v)) == 0) {
    //         printf("finished.\n");
    //         break;
    //     }
    //     printf("Enter and edge (to): ");
    //     if (scanf("%d", &(e.w)) == 0) {
    //         printf("finished.\n");
    //         break;
    //     }
    //     insertEdge(g, e);
    // }

   //debug codes
    e.v = 0;
    e.w = 1;
    insertEdge(g, e);
    e.v = 1;
    e.w = 2;
    insertEdge(g, e);
    e.v = 4;
    e.w = 3;
    insertEdge(g, e);
    e.v = 6;
    e.w = 5;
    insertEdge(g, e);
    e.v = 6;
    e.w = 7;
    insertEdge(g, e);
    e.v = 5;
    e.w = 7;
    insertEdge(g, e);
    e.v = 5;
    e.w = 8;
    insertEdge(g, e);
    e.v = 7;
    e.w = 8;
    insertEdge(g, e);
    printf("\n");
    showGraph(g);
    printf("\n");

    //calculate number of compnent

    free(componentOf);
    return EXIT_SUCCESS;
}
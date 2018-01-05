#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Graph.h"

int main(void) {
    int nvert;  // number of vertices
    Edge e;     // an edge
    // create new empty graph
    printf("Enter the number of vertices: ");
    scanf("%d", &nvert);
    Graph g = newGraph(nvert);
    // insert edge into graph
    while (true) {
        printf("Enter and edge (from): ");
        if (scanf("%d", &(e.v)) == 1) {
            printf("finished.\n");
            break;
        }
        printf("Enter and edge (to): ");
        if (scanf("%d", &(e.w)) == 1) {
            printf("finished.\n");
            break;
        }
        insertEdge(g, e);
    }

    return EXIT_SUCCESS;
}
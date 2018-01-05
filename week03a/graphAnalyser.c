#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int main(void) {
    int nV = 6;  // number of vertices
    Edge e;     // an edge
    int min = nV - 1;
    int max = 0;
    int i, j, k;  // index of edges
    int degree;     //degree of an vertice
    // create new empty graph
    printf("Enter the number of vertices: ");
    scanf("%d", &nV);
    Graph g = newGraph(nV);
    //insert edge into graph
    while (true) {
        printf("Enter and edge (from): ");
        if (scanf("%d", &(e.v)) == 0) {
            printf("finished.\n");
            break;
        }
        printf("Enter and edge (to): ");
        if (scanf("%d", &(e.w)) == 0) {
            printf("finished.\n");
            break;
        }
        insertEdge(g, e);
    }
    // debug codes
    // e.v = 0;
    // e.w = 1;
    // insertEdge(g, e);
    // e.v = 1;
    // e.w = 2;
    // insertEdge(g, e);
    // e.v = 4;
    // e.w = 2;
    // insertEdge(g, e);
    // e.v = 1;
    // e.w = 3;
    // insertEdge(g, e);
    // e.v = 3;
    // e.w = 4;
    // insertEdge(g, e);
    // e.v = 1;
    // e.w = 5;
    // insertEdge(g, e);
    // e.v = 5;
    // e.w = 3;
    // insertEdge(g, e);
    // e.v = 2;
    // e.w = 3;
    // insertEdge(g, e);
    // printf("\n");
    // showGraph(g);
    // printf("\n");
    // calculate min and max

    for (i = 0; i < nV; i++) {
        degree = 1;
        for (j = 0; j < nV; j++) {
            if ((i != j) && adjacent(g, i, j)) {
                degree++;
            }
        }
        if (degree < min) {
            min = degree;
        }
        if (degree > max) {
            max = degree;
        }
    }
    printf("Minimum degree: %d\n", min);
    printf("Maximum degree: %d\n", max);
    printf("Nodes of minimum degree:\n");
    for (i = 0; i < nV; i++) {
        degree = 1;
        for (j = 0; j < nV; j++) {
            if ((i != j) && adjacent(g, i, j)) {
                degree++;
            }
        }
        if (degree == min) {
            printf("%d\n", i);
        }
    }
    printf("Nodes of maximum degree:\n");
    for (i = 0; i < nV; i++) {
        degree = 1;
        for (j = 0; j < nV; j++) {
            if ((i != j) && adjacent(g, i, j)) {
                degree++;
            }
        }
        if (degree == max) {
            printf("%d\n", i);
        }
    }
    // find triangles
    printf("Triangles:\n");
    for (i = 0; i < nV - 2; i++) {
        for (j = i + 1; j < nV -1 ; j++) {
            if (adjacent(g, i, j)) {
                for (k = j + 1; k < nV; k++) {
                    if (adjacent(g, i, k) && adjacent(g, j, k)) {
                        printf("%d-%d-%d\n", i, j, k);
                    }
                }
            }
        }
    }
    return EXIT_SUCCESS;
}
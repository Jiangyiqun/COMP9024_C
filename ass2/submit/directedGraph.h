// File: directedGraph.c
// Author: Jack Jiang (z5129432)
// Data: 2018x1
// Description:
//     An Adjacency Matrix Representation for directed graph
//     This file is originally come form COMP9024 lecture
//     Jack Jiang modified it to a directed graph representation.
//     and add a function to get the outgoing degree of any vertice
// Reference:
//     https://www.cse.unsw.edu.au/~cs9024/18x1/slides/week03a/progs/Graph.h

#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <stdbool.h>

typedef struct GraphRep *Graph;

// vertices are ints
typedef int Vertex;

// edges are pairs of vertices (end-points)
// edges have direction, which are form v to w
typedef struct Edge {
   Vertex v;
   Vertex w;
} Edge;

Graph newGraph(int);
void  insertEdge(Graph, Edge);
void  removeEdge(Graph, Edge);
bool  adjacent(Graph, Vertex, Vertex);
void  showGraph(Graph);
void  freeGraph(Graph);
int outDegree(Graph, Vertex);

#endif
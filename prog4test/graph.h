//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439


#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include "list.h"

typedef struct graph *graphRef;

typedef struct graph {
   int size;
   listRef vertexArray[];
} graphType;


/*** Constructors ***/

graphRef newGraph(int size);

void freeGraph(graphRef G);

/*** Access Functions ***/

int getDistance(graphRef G, int destination);   

listRef getPathTo(graphRef G, int destination);


/*** Manipulation Procedures ***/

void addEdge(graphRef G, int from, int to);

void doBFS(graphRef G, int source);

void resetGraph(graphRef G);

/*** Others ***/

void printDirections(graphRef G, int source, int destination);



#endif

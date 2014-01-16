//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graph.h"
#include "list.h"

/*** Constructors ***/

graphRef newGraph(int size){            //creates a new graph object
   graphRef graph = malloc(sizeof(graphType) + (sizeof(listRef)*(size)));
   for(int i = 0; i < size; i++){
      graph->vertexArray[i] = newList();
   }
   graph->size = size;
   return graph;
}

void freeGraph(graphRef G){
   memset(G, 0, (sizeof(graphType) + sizeof(listRef)*G->size));
   free(G);
   G = NULL;
}

/*** Access Functions ***/

int getDistance(graphRef G, int destination){         //gets the distance from a source
   if(G->vertexArray[destination]->distance != 0)     //to a destination
      return G->vertexArray[destination]->distance;
   else
      return -1;
}

listRef getPathTo(graphRef G, int destination){      //creates a list that is the path from a
   if(getDistance(G, destination) == -1)             //source to destination
      return NULL;
   else{
      listRef stack = newList();
      insert(stack, destination);
      int current = G->vertexArray[destination]->parent;
      while(current != -1){
         insert(stack, current);
         current = G->vertexArray[current]->parent;
      }
      return stack;
   }
}

/*** Manipulation Procedures ***/

void addEdge(graphRef G, int from, int to){         //adds an edge to a graph
   insert(G->vertexArray[from], to);
}


void doBFS(graphRef G, int source){              //performs breadth first search of a graph
   listRef queue = newList();                    //modifies the color, parent, and distance
   G->vertexArray[source]->color = 1;            //properties of vertexes
   insert(queue, source);
   while(!isEmpty(queue)){
      int u = getFirst(queue);
      for(nodeRef curr = G->vertexArray[u]->first; curr != NULL; curr = curr->next){
         if(G->vertexArray[curr->vertex]->color == 0){
            G->vertexArray[curr->vertex]->distance = G->vertexArray[u]->distance + 1;
            G->vertexArray[curr->vertex]->parent = u;
            insert(queue, curr->vertex);
            G->vertexArray[curr->vertex]->color = 1;
         }
      }
   G->vertexArray[u]->color = 2;
   deleteFirst(queue);
   }
}

void resetGraph(graphRef G){            //resets all vertices color, parent, and distance properties
   for(int i = 0; i < G->size; i++){
      G->vertexArray[i]->color = 0;
      G->vertexArray[i]->parent = -1;
      G->vertexArray[i]->distance = 0;
   }
}

/*** Others ***/

void printDirections(graphRef G, int source, int destination){   //prints a graph using all
   resetGraph(G);                                                //the previous functions above
   doBFS(G, source);
   int distance = getDistance(G, destination);
   listRef directions = getPathTo(G, destination);
   if(distance != -1){
      printf("To get from %d to %d requires %d edges, follow the path", source, destination, distance);
      for(nodeRef curr = directions->last; curr != NULL; curr = curr->prev){
         printf(" %d", getLast(directions));
         deleteLast(directions);
      }
      printf(".\n");
   }else{
      printf("There is no way to get from %d to %d in the graph.\n", source, destination);
   }
}



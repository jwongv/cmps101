//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439


#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "graph.h"

int main(){


   printf("\n\n\n");
   printf("Welcome to the graph driver!\n");
   printf("Creating a new graph with 3 vertices\n");

   graphRef graph = newGraph(5);

   printf("Inserting 2 1 into vertex 0\n");
   printf("Inserting 4 3 2 into vertex 1\n");
   printf("Inserting 0 1 3 into vertex 2\n");

   addEdge(graph, 0, 2);
   addEdge(graph, 0, 1);
   addEdge(graph, 1, 4);
   addEdge(graph, 1, 3);
   addEdge(graph, 1, 2);
   addEdge(graph, 2, 0);
   addEdge(graph, 2, 1);
   addEdge(graph, 2, 3);


   printf("Printing out a view of the graph array\n");

   for(int i = 0; i < graph->size; i++){
      printf("%d:", i);
      for(nodeRef curr = graph->vertexArray[i]->first; curr != NULL; curr = curr->next){
         printf("%d->", curr->vertex);
      }
      printf("\n");
   }




   printf("Testing BFS with source 0\n");

   doBFS(graph, 0);

   printf("Printing distance from 0 to 4. Result should be 2\n");
   printf("%d\n", getDistance(graph, 4));

   printf("Printing path from 0 to 4. Result should be 0 1 4\n");
   listRef path = getPathTo(graph, 4);
   for(nodeRef curr = path->last; curr != NULL; curr = curr->prev){
      printf("%d ", curr->vertex);
   }
   printf("\n");

   printf("Testing graph reset. Resets colors, parents, and distance\n");
   printf("Printing distance from 0 to 4. Should be -1 because of reset\n");

   resetGraph(graph);
   printf("%d\n", getDistance(graph, 4));

   printf("Testing printDirections function\n");
   resetGraph(graph);
   printDirections(graph, 0, 4);

   printf("Freeing the graph\n");
   freeGraph(graph);

   printf("The graph driver is now complete :)\n");







return 0;

}

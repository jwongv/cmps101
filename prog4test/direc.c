//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "graph.h"

int main(int argc, char **argv){
   int EXIT_STATUS = 0;

   FILE *info = fopen(argv[1], "r");
   if(info == NULL){  //check for valid filename, if not exit with status 1
      fflush(NULL);
      fprintf(stderr,"Invalid file name!\n");
      fflush(NULL);
      EXIT_STATUS = 1;
      exit(EXIT_STATUS);
   }


   int vertices;
   int queries;
   char buffer[1000];
   char delimiters[] = ". ;,\n";
   char *token;

   fscanf(info, "%d", &vertices);      //scans in number of vertices
   fscanf(info, "%d", &queries);       //scans in number of quereies
   fgets(buffer, 1000, info);          //fgets called to get to next line

   graphRef graph = newGraph(vertices);  //creates new graph

   char *end;
   int base = 10;
   int vertexindex;
   int n;


   for(int i = 0; i < vertices; i++){             //loops to scan in a line at a time
      fgets(buffer, 1000, info);                  //converts the first section to a string
      token = strtok(buffer, delimiters);         //then converts it to an integer
      vertexindex = strtol(token, &end, base);    //it is then added to a vertex list
      token = strtok(NULL, delimiters);
      while(token != NULL){
         n = strtol(token, &end, 10);
         addEdge(graph, vertexindex, n);
         token = strtok(NULL, delimiters);
      }
   }


   int source;
   int destination;

   for(int i = 0; i < queries; i++){        //loops to scan and perform each query
      fscanf(info, "%d", &source);
      fscanf(info, "%d", &destination);
      printDirections(graph, source, destination);
   }



   return EXIT_STATUS;

}

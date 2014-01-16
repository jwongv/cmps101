//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "insertionSort.h"
#include "heap.h"
#include "heapSort.h"

int main(int argc, char **argv){
   int EXIT_STATUS = 0;

   //scan in the file
   FILE *info = fopen (argv[1], "r");
   if(info == NULL){
      fflush(NULL);
      fprintf(stderr,"Invalid file name!\n");
      fflush(NULL);
      EXIT_STATUS = 1;
      exit(EXIT_STATUS);
   }

   //scan in the number of elements and create an array for it
   int numelements;
   fscanf(info, "%d", &numelements);
   int insertionArray[numelements];
   int heapArray[numelements];
   int check = 0;
   int i = 0;
   int data;

   //scan through the file and insert it into two arrays to sort
   while(check != EOF){
      check = fscanf(info, "%d", &data);
      insertionArray[i] = data;
      heapArray[i] = data;
      i++;
   }

   //measure the time of insertionSort
   clock_t insertStart, insertDuration;
   insertStart = clock();
   insertionSort(insertionArray, numelements);
   insertDuration = clock() - insertStart;
   printf("Insertion sort took %f seconds.\n", ((float)insertDuration)/CLOCKS_PER_SEC);

   //measure the time of heapSort
   clock_t heapStart, heapDuration;
   heapStart = clock();
   heapSort(heapArray, numelements);
   heapDuration = clock() - heapStart;
   printf("Heap sort took %f seconds.\n", ((float)heapDuration)/CLOCKS_PER_SEC);

   return EXIT_STATUS;
}

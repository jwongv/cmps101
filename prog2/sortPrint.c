//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439


#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "insertionSort.h"
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

   int insertCheck = 1;
   int heapCheck = 1;

   //sort the array using insertion sort and print/confirm
   printf("Insertion sort results:\n");
   insertionSort(insertionArray, numelements);
   for(int i = 0; i < numelements; i++){
      printf("%d\n", insertionArray[i]);
   }
   for(int i = 0; i < numelements-1; i++){
      if(insertionArray[i] > insertionArray[i+1])
         insertCheck = 0;
   }
   if(insertCheck)
      printf("Insertion sort was successful!\n");
   else
      printf("Insertion sort failed!\n");

   //sort the array using heap sort and print/confirm
   printf("\nHeap sort results:\n");
   heapSort(heapArray, numelements);
   for(int i = 0; i < numelements; i++){
      printf("%d\n", heapArray[i]);
   }
   for(int i = 0; i < numelements-1; i++){
      if(heapArray[i] > heapArray[i+1])
         heapCheck = 0;
   }
   if(heapCheck)
      printf("Heap sort was successful!\n");
   else
      printf("Heap sort failed!\n");

   return EXIT_STATUS;
}

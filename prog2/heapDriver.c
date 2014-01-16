//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439


#include <stdio.h>
#include "heap.h"
#include "heapSort.h"

int main (int argc, char **argv){

   printf("Welcome to the heap driver program!\n");
   //testing insertion into a heap and testing printheap
   printf("Inserting several nodesand printing the heap\n");
   printf("Result should be 45135, 2534, 325, 50, 211, 25, 3, 294, 1.\n");
   HeapRef heap = newHeap(10);
   insert(heap, 50);
   insert(heap, 211);
   insert(heap, 45135);
   insert(heap, 3);
   insert(heap, 325);
   insert(heap, 2344);
   insert(heap, 25);
   insert(heap, 2534);
   insert(heap, 294);
   insert(heap, 1);
   printHeap(heap);

   //testing maxValue
   printf("\nPrinting max of heap, result should be 45135\n");
   printf("%d\n", maxValue(heap));

   printf("\n");
   //testing deleting the max nodes from a heap
   printf("Deleting 2 max nodes and reheapifying\n");
   printf("Result should be 2344, 325, 211, 294, 50, 1, 25, 3.\n");
   deleteMax(heap);
   deleteMax(heap);
   printHeap(heap);
   printf("\n");

   //testing heap sort function
   printf("Testing heap sort. Result should be 1, 3, 25, 42, 50, 211, 294, 325, 543, 2311, 2344, 2534, 45135.\n\n");
   int keys [] = {50, 211, 45135, 3, 325, 2344, 25, 2534, 294, 1, 42, 543, 2311};
   heapSort(keys, 13);
   for(int i = 0; i < 13; i++){
      printf("%d\n", keys[i]);
   }

   printf("The heap driver is now done!\n");

   return 0;
}

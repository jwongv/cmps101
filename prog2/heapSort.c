//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "heapSort.h"
#include "heap.h"


void heapSort(int keys[], int numKeys){   //sorts an array using a heap structure
   HeapRef heap = newHeap(numKeys);       // builds a heap, inserts all array elements, then sorts
   for(int i = 0; i < numKeys; i++){      // post: isEmpty();
      insert(heap, keys[i]);
   }
   for(int i = numKeys-1; i >= 0; i--){
      keys[i] = maxValue(heap);
      deleteMax(heap);
   }
   assert(isEmpty(heap));
   freeHeap(heap);
}


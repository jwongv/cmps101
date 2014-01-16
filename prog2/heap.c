//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "heap.h"


typedef struct Heap{
   int maxSize;
   int currentSize;
   int keys[];
} HeapType;


/*** Constructors ***/
HeapRef newHeap(int maxSize){   //creates a new heap object
   HeapRef heap = malloc(sizeof(HeapType) + (sizeof(int)*(maxSize+1)));
   assert(heap != NULL);
   heap->maxSize = maxSize;
   heap->currentSize = 0;
   return heap;
}

void freeHeap(HeapRef h){   //frees a heap object
   memset(h, 0, sizeof(HeapType) + (sizeof(int)*(h->maxSize+1)));
   free(h);
   h = NULL;
}

/*** Access Functions ***/
int isFull(HeapRef h){             //returns true if a heap is full
   if(h->keys[h->maxSize+1] != 0)
      return 1;
   else
      return 0;
}

int isEmpty(HeapRef h){   //returns true if a heap is empty
   if(h->keys[1] == 0)
      return 1;
   else
      return 0;
}

int maxValue(HeapRef h){   //returns the max value of a heap (the first slot)
   if(!isEmpty(h))         //pre: !isEmpty()
      return h->keys[1];
   else
      return 0;
}

/*** Manipulation Functions ***/

void deleteMax(HeapRef h){   //deletes themax value of a heap (the first slot)
   if(!isEmpty(h)){          //pre: !isEmpty()
      h->keys[1] = h->keys[h->currentSize];
      h->keys[h->currentSize] = 0;
      h->currentSize--;
      heapify(h);
   }
}

void insert(HeapRef h, int priority){   //inserts an integer to a heap
   if(!isFull(h)){                      //pre: !isFull() post: !isEmpty()
      h->keys[h->currentSize+1] = priority;
      h->currentSize++;
      int i = h->currentSize;
      while(i > 1){
         int tmp = h->keys[i];
         if(h->keys[i] >= h->keys[i/2]){
            h->keys[i] = h->keys[i/2];
            h->keys[i/2] = tmp;
         }
         i = i/2;
      }
   }
   assert(!isEmpty(h));
}

void heapify(HeapRef h){   //starting from the top, sorts a heap after a node is deleted. called in deleteMax()
   if(!isEmpty(h)){        //pre: !isEmpty() post: !isEmpty()
      int i = 1;
      while(i < h->currentSize){
         int left = h->keys[i*2];
         int right = h->keys[i*2+1];
         int tmp = h->keys[i];
         if(left >= right && i*2 <= h->currentSize && h->keys[i] < h->keys[i*2]){
            h->keys[i] = left;
            h->keys[i*2] = tmp;
            i = i*2;
         }else if(left <= right && i*2+1 <=h->currentSize && h->keys[i] < h->keys[i*2+1]){
            h->keys[i] = right;
            h->keys[i*2+1] = tmp;
            i = i*2+1;
         }else{
            break;
         }
      }
   assert(!isEmpty(h));
   }
}


/*** Other Functions ***/

void printHeap(HeapRef h){     //prints out a heap
   if(!isEmpty(h)){            //pre: !isEmpty()
      for(int i = 1; i < h->currentSize+1; i++){
         printf("%d\n",h->keys[i]);
      }
   }
}












//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439

#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Heap *HeapRef;



/*** Constructors ***/
HeapRef newHeap(int maxSize);   //creates a new heap object

void freeHeap(HeapRef h);   //frees a heap object

/*** Access Functions ***/
int isFull(HeapRef h);   //returns true if a heap is full

int isEmpty(HeapRef h);   //returns true if a heap is empty

int maxValue(HeapRef h);   //returns the max value of a heap
                           //pre: !isEmpty()



/*** Manipulation Functions ***/
void deleteMax(HeapRef h);   //deletes the max value of a heap (the first slot)
                             //pre: !isEmpty()

void insert(HeapRef h, int priority);   //inserts an intger to a heap
                                        //pre: !isFull() post: !isEmpty()

void heapify(HeapRef h);   //starting from the top, sorts a heap after a node is deleted. called in deleteMax()
                           //pre: !isEmpty() post: !isEmpty()

/*** Other Functions ***/
void printHeap(HeapRef h);    //prints out a heap
                              //pre: !isEmpty()
#endif


//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "insertionSort.h"

void insertionSort(int keys[], int numKeys){
   for(int i = 1; i<numKeys; i++){
      int slot = i;
      int copy = keys[i];
      for(;slot > 0; --slot){
         if(copy > keys[slot-1])
            break;
         keys[slot] = keys[slot-1];
      }
      keys[slot] = copy;
   }
}

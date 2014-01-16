//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "booklist.h"
#include "List.h"
#include "hash.h"


/*** Constructors ***/

hashRef newHash(int hashSize){
   hashRef newhash = malloc(sizeof(HashType) + (sizeof(bookListRef)*(hashSize)));
   newhash->size = hashSize;
   newhash->bookcount = 0;
   newhash->load = (newhash->bookcount)/(newhash->size);
   for(int i = 0; i < hashSize; i++){
      newhash->purchasedBooks[i] = newBookList();
   }
   return newhash;
}

void freeHash(hashRef H){
   memset(H, 0, sizeof(HashType) + (sizeof(bookListRef)*(H->size)));
   free(H);
   H = NULL;
}

/*** Access Functions ***/
int tooFull(hashRef H){
   if(H->load > 0.5)
      return 1;
   return 0;
}

/*** Manipulation Proecdures ***/
void insertBookList(hashRef H, long data){
   int index = hashKey(H, data);
   if(!inList(H->purchasedBooks[index], data))
      insertBook(H->purchasedBooks[index], data);
   //if book is in list, update count
}


/*** Others ***/
int hashKey(hashRef H, long key){
   int index = key % H->size;
   return index;
}

hashRef double_array_hash(hashRef H){
   hashRef newhash = newHash((H->size)*2);
   bookListRef rawr = H->purchasedBooks[1];
   bookNodeRef current = rawr->first;
   for(int i = 0; i < H->size; i++){
      for(bookNodeRef current = H->purchasedBooks[i]->first; current != NULL; current = current->next){
         insertBookList(newhash, current->data);
         int indexold = hashKey(H, current->data);
         int indexnew = hashKey(newhash, current->data);
         bookNodeRef old = findBook(H->purchasedBooks[indexold], current->data);
         bookNodeRef new = findBook(newhash->purchasedBooks[indexnew], current->data);
         new->copurchases = old->copurchases;
      }
   }
   freeHash(H);
   return newhash;
}

void printHash(hashRef H){
   for(int i = 0; i < H->size; i++){
      for(bookNodeRef current = H->purchasedBooks[i]->first; current != NULL; current = current->next){
         printf("%ld-> ", current->data);
      }
   printf("\n");
   }
}





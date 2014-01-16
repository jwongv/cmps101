//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439

#ifndef __HASH_H__
#define __HASH_H__

#include "booklist.h"
#include "List.h"

typedef struct hash *hashRef;

typedef struct hash {
   int size;
   double load;
   int bookcount;
   bookListRef purchasedBooks[];
} HashType;



/*** Constructor ***/
hashRef newHash(int hashSize);

void freeHash(hashRef H);

/*** Access Functions ***/
int tooFull(hashRef H);

/*** Manipulation Procedures ***/

void insertBookList(hashRef H, long data);


/*** Others ***/
int hashKey(hashRef H, long key);

hashRef double_array_hash(hashRef H);

void printHash(hashRef H);

#endif

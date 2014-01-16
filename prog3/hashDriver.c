//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439

#include <stdio.h>
#include <stdlib.h>

#include "List.h"
#include "booklist.h"
#include "hash.h"

int main(){
 
   printf("Welcome to the hash driver!\n");
   printf("Creating new hash of size 10\n");
   hashRef testhash = newHash(10);
   
   printf("Testing hash function with #123. Should print out 3\n");
   printf("%d\n", hashKey(testhash, 123));


   printf("Inserting 4 books into list\n");
   insertBookList(testhash, 1);
   insertBookList(testhash, 2);
   insertBookList(testhash, 3);
   insertBookList(testhash, 4);
   printf("Checking if hash too full. Should print not full\n");
   if (tooFull(testhash))
      printf("Too full!\n");
   else
      printf("Not too full!\n");

   printf("Inserting 2 more books\n");
   insertBookList(testhash, 5);
   insertBookList(testhash, 6);
   
   printf("Checking if hash too full again. Should print too full\n");
   if (tooFull(testhash))
      printf("Too full!\n");
   else
      printf("Not too full!\n");


   printf("Inserting more books to make sure they are getting hashed correclty\n");

   printf("Printing the hash\n");

   insertBookList(testhash, 12);
   insertBookList(testhash, 23);
   insertBookList(testhash, 34);
   insertBookList(testhash, 15);
   insertBookList(testhash, 56);
   insertBookList(testhash, 17);
   insertBookList(testhash, 654);
   insertBookList(testhash, 433);
   insertBookList(testhash, 5);

   printHash(testhash);

   return 0;
}


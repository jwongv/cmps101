//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439


#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(){

   printf("\n\n\n");
   printf("Welcome to the list driver\n");
   printf("Creating a new list...\n");

   listRef list = newList();

   printf("Inserting 1, 2, 3, 4 into the list\n");

   insert(list, 1);
   insert(list, 2);
   insert(list, 3);
   insert(list, 4);

   printf("Checking if list is empty\n");

   if(isEmpty(list))
      printf("List is empty!\n");
   else
      printf("List is not empty!\n");


   printf("Testing get first. Should be 1\n");
   printf("%d\n", getFirst(list));

   printf("Testing get last. Should be 4\n");
   printf("%d\n", getLast(list));


   printf("Testing delete first and get last. Result should be 2 and 3\n");
   deleteFirst(list);
   deleteLast(list);
   printf("%d\n", getFirst(list));
   printf("%d\n", getLast(list));

   printf("Deleting the leftover nodes...\n");

   deleteFirst(list);
   deleteFirst(list);

   printf("Checking if list is empty\n");

   if(isEmpty(list))
      printf("List is empty!\n");
   else
      printf("List is not empty!\n");

   printf("Freeing the list\n");
   freeList(list);

   printf("The list driver is now finished :)\n");

   return 0;
}

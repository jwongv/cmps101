//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439

#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "booklist.h"

int main(){

   printf("Welcome to the bookList driver!\n");

   printf("Creating a new empty book list\n");
   bookListRef booklist1 = newBookList();
   printf("Checking if the list is empty! Should print 'It's emtpy'\n");

   if(isBEmpty(booklist1))
      printf("It's empty!\n");
   else
      printf("Not empty!\n");

   printf("Inserting book #1234\n");
   insertBook(booklist1, 1234);

   printf("Checking to see if 1234 is in the list. Should print 1234 is in the list\n");
   if(inList(booklist1, 1234))
      printf("1234 is in the list!\n");
   else
      printf("1234 is not in the list!\n");

   printf("The book list driver is complete!\n");

}

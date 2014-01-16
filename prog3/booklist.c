//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439

#include <stdlib.h>
#include <stdio.h>

#include "booklist.h"
#include "List.h"



/*** Constructors ***/
bookListRef newBookList(void){
   bookListRef B = malloc(sizeof(bookListType));
   B->first = NULL;
   B->last = NULL;
   return B;
}

/*** Access Functions ***/

int isBEmpty(bookListRef B){
   if(B->first == NULL)
      return 1;
   else
      return 0;
}

int inList(bookListRef B, long data){
   bookNodeRef current = B->first;
   while(current != NULL){
      if (data == current->data)
         return 1;
   current = current->next;
   }
   return 0;
}

bookNodeRef findBook(bookListRef B, long data){
   bookNodeRef current = B->first;
   while(current != NULL){
      if(data == current->data)
         return current;
   current = current->next;
   }
   return NULL;
}





/*** Manipulation Procedures ***/

void insertBook(bookListRef B, long data){

   if(!inList(B, data)){

      bookNodeRef newnode = malloc(sizeof(bookNodeType));
      newnode->data = data;
      newnode->copurchases = newList();
      newnode->next = NULL;
      newnode->prev = NULL;

      if(isBEmpty(B)){
         B->first = newnode;
         B->last = newnode;
      }else{
         B->last->next = newnode;
         newnode->prev = B->last;
         B->last = newnode;
      }
   }
}







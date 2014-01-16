//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

/*** Constructors ***/

listRef newList(void){                        //creates a new list object
   listRef list = malloc(sizeof(listType));
   list->first = NULL;
   list->last = NULL;
   list->length = 0;
   list->color = 0;
   list->parent = -1;
   list->distance = 0;
   return list;
}

void freeList(listRef L){
   memset(L, 0, sizeof(listType));
   free(L);
   L=NULL;
}

/*** Access Functions ***/

int isEmpty(listRef L){                      //checks if a list is empty
   if(L->first == NULL)
      return 1;
   else
      return 0;
}

int getFirst(listRef L){                     //gets the first vertex in a list
   return L->first->vertex;
}

int getLast(listRef L){                      //gets the last object in a list
   return L->last->vertex;
}



/*** Manipulation Procedures ***/

void insert(listRef L, int vertex){                 //inserts a node to the end of a list
   nodeRef newnode = malloc(sizeof(nodeType));
   newnode->vertex = vertex;
   newnode->next = NULL;
   newnode->prev = NULL;
   if(isEmpty(L)){
      L->first = newnode;
      L->last = newnode;
   }else{
      newnode->prev = L->last;
      L->last->next = newnode;
      L->last = newnode;
   }
   L->length++;
}


void deleteFirst(listRef L){             //deletes the first node of a list
   if(!isEmpty(L)){                      //pre: !isEmpty()
      nodeRef oldnode = L->first;
      if(L->first == L->last){
         L->first = NULL;
         L->last = NULL;
      }else{
         L->first = L->first->next;
         L->first->prev = NULL;
      }
      free(oldnode);
      oldnode = NULL;
      L->length--;
   }
}

void deleteLast(listRef L){          //deletes the last node of a list
   if(!isEmpty(L)){                  //pre: !isEmpty()
      nodeRef oldnode = L->last;
      if(L->last == L->first){
         L->first = NULL;
         L->last = NULL;
      }else{
         L->last = L->last->prev;
         L->last->next = NULL;
      }
   free(oldnode);
   oldnode = NULL;
   L->length--;
   }
}











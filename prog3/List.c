//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "List.h"



/*** Constructors ***/
ListRef newList(void){  //creates a new list by mallocing the space for it and making all the node pointers NULL
   ListRef list = malloc (sizeof(ListType));
   assert (list!=NULL);
   list->first = NULL;
   list->last = NULL;
   list->current = NULL;
   list->length = 0;
   return list;
}
 
void freeList(ListRef L){  //frees a list
   memset(L, 0, sizeof(ListType));
   free(L);
   L = NULL;
}

/*** Access functions ***/
int isEmpty(ListRef L){   //checks if the list is empty
   if(L->first == NULL)
      return 1;
   else
      return 0;
}

int offEnd(ListRef L){   //checks if current pointer is null
   if(L->current == NULL)
      return 1;
   else
      return 0;
}

int atFirst(ListRef L){                      //checks if current is first pointer
   if(L->current == L->first && !offEnd(L))  //pre: !offEnd()
      return 1;
   else
      return 0;
}

int atLast(ListRef L){                      //checks if current is last pointer
   if(L->current == L->last && !offEnd(L))  //pre: !offEnd()
      return 1;
   else
      return 0;
}

long getFirst(ListRef L){  //returns the data in the first node
   if(!isEmpty(L))         //pre: !isEmpty()
      return L->first->data;
   return NULL;
}

long getLast(ListRef L){  //returns the data in the last node
   if(!isEmpty(L))        //pre: !isEmpty()
      return L->last->data;
   return NULL;
}

long getCurrent(ListRef L){  //returns the data in the current node
   if(!offEnd(L))            //pre: !offEnd()
      return L->current->data;
   return NULL;
}

int getLength(ListRef L){  //returns the length of a list
   return L->length;
}

int getCount(NodeRef N){
   return N->count;
}

int equals(ListRef A, ListRef B){  //checks if two lists are equal
   if (A == B)
      return 1;
   else
      return 0;
}


int inCList(ListRef L, long data){
   for(NodeRef curr = L->first; curr != NULL; curr = curr->next){
      if(curr->data == data)
         return 1;
   }
   return 0;
}

NodeRef highestCount(ListRef L, ListRef cust){
   NodeRef curr = L->first;
   NodeRef greatest = curr;
   int greatestcount = 0;
  // curr = curr->next;
   while(curr != NULL){
      if((curr->count > greatestcount) && !inCList(cust, curr->data)){
         greatest = curr;
         greatestcount = curr->count;
      }
      curr = curr->next;
   }
   return greatest;
}

NodeRef findCBook(ListRef L, long data){
   for(NodeRef curr = L->first; curr != NULL; curr = curr->next){
      if(curr->data == data)
         return curr;
   }
   return NULL;
}



/*** Manipulation procedures ***/

void makeEmpty(ListRef L){  //empties a list and frees all the nodes. starts at first
    L->current = L->first;
    while(!isEmpty(L)){
       NodeRef oldnode = L->current;
       L->current = L->current->next;
       L->first = L->current;
       free(oldnode);
       oldnode = NULL;
       L->length--;
    }
    assert(isEmpty(L));     //post: isEmpty()
}

void moveFirst(ListRef L){  //moves current to first
   if(!isEmpty(L))          //pre: !isEmpty()
      L->current = L->first;
   assert(!offEnd(L));      //post: !offEnd()
}

void moveLast(ListRef L){  //moves current to last
   if(!isEmpty(L))         //pre: !isEmpty()
      L->current = L->last;
   assert(!offEnd(L));     //post: !offEnd()
}

void movePrev(ListRef L){  //moves current to previous node
   if(!offEnd(L))          //pre: !offEnd()
      L->current = L->current->prev;
}

void moveNext(ListRef L){  //moves current to next node
   if(!offEnd(L))          //pre: !offEnd()
      L->current = L->current->next;
}

void upCount(NodeRef N){
   N->count++;
}



void insertBeforeFirst(ListRef L, long data){  //inserts new node before first

   NodeRef newnode = malloc(sizeof(NodeType));
   newnode->data = data;
   newnode->count = 1;
   newnode->next = NULL;
   newnode->prev = NULL;
   if(isEmpty(L)){                             //checks if list is empty
      L->first = newnode;
      L->last = newnode;
      L->current = newnode;
   }else{                                      //otherwise connects node to the list
      newnode->next = L->first;
      L->first->prev = newnode;
      L->first = newnode;
   }
   L->length++;
   assert(!isEmpty(L));                        //post: !isEmpty()

}

void insertAfterLast(ListRef L, long data){  //inserts new node after last

   if(inCList(L, data)){
      upCount(findCBook(L, data));
   }else{

      NodeRef newnode = malloc(sizeof(NodeType));
      newnode->data = data;
      newnode->count = 1;
      newnode->next = NULL;
      newnode->prev = NULL;
      if(isEmpty(L)){                           //checks if list is empty
         L->first = newnode;
         L->last = newnode;
         L->current = newnode;
      }else{                                    //otherwise connects node to list
         L->last->next = newnode;
         newnode->prev = L->last;
         L->last = newnode;
      }
      L->length++;
      assert(!isEmpty(L));                      //post: !isEmpty()

   }
}

void insertBeforeCurrent(ListRef L, long data){  //inserts new node before current
   if(!offEnd(L)){                               //pre: !offEnd
      NodeRef newnode = malloc(sizeof(NodeType));
      newnode->data = data;
      newnode->count = 1;
      newnode->next = NULL;
      newnode->prev = NULL;
      if(isEmpty(L)){                            //checks if list is empty
         L->first = newnode;
         L->last = newnode;
         L->current = newnode;
      }else if (atFirst(L)){
         newnode->next = L->first;
         L->first->prev = newnode;
         L->first = newnode;
         L->current = newnode;
      }else{                                     //otherwise connects node to list
         newnode->next = L->current;
         newnode->prev = L->current->prev;
         L->current->prev->next = newnode;
         L->current->prev = newnode;
      }
      L->length++;
      assert(!offEnd(L) && !isEmpty(L));        //post: !offEnd() and !isEmpty()
   }
}

void insertAfterCurrent(ListRef L, long data){  //inserts node after current
   if(!offEnd(L)){  //pre: !offEnd
      NodeRef newnode = malloc(sizeof(NodeType));
      newnode->data = data;
      newnode->count = 1;
      newnode->next = NULL;
      newnode->prev = NULL;
      if(isEmpty(L)){                           //checks if list is empty
         L->first = newnode;
         L->last = newnode;
         L->current = newnode;
      }else if(atLast(L)){
         L->last->next = newnode;
         newnode->prev = L->last;
         L->last = newnode;
      }else{                                    //otherwise connects node to list
         newnode->next = L->current->next;
         newnode->prev = L->current;
         L->current->next->prev = newnode;
         L->current->next = newnode;
      }
      L->length++;
      assert(!offEnd(L) && !isEmpty(L));        //post: !offEnd() and !isEmpty()
   }
}


void deleteFirst(ListRef L){     //deletes first node and frees it
    if(!isEmpty(L)){             //pre: !isEmpty()
       NodeRef oldnode = L->first;
       if(L->first == L->last){  //checks if list is only a single node
          L->first = NULL;
          L->last = NULL;
          L->current = NULL;
       }else{
          if(atFirst(L))
             L->current = L->current->next;
          L->first = L->first->next;
          L->first->prev = NULL;
       }
       free(oldnode);
       oldnode = NULL;
       L->length--;
    }
}

void deleteLast(ListRef L){      //deletes last node and frees it
   if(!isEmpty(L)){              //pre: !isEmpty()
      NodeRef oldnode = L->last;
      if(L->first == L->last){   //checks if list is only a single node
         L->first = NULL;
         L->last = NULL;
         L->current = NULL;
      }else{
         if(atLast(L))
            L->current = L->current->prev;
         L->last = L->last->prev;
         L->last->next = NULL;
      }
      free(oldnode);
      oldnode = NULL;
      L->length--;
   }
}

void deleteCurrent(ListRef L){     //deletes current node and frees it
   if(!isEmpty(L) && !offEnd(L)){  //pre: !isEmpty() and !offEnd()
      if(atLast(L))
         deleteLast(L);
      else if(atFirst(L))
         deleteFirst(L);
      else{
         NodeRef oldnode = L->current;
         L->current->prev->next = L->current->next;
         L->current->next->prev = L->current->prev;
         L->current = L->current->next;
         free(oldnode);
         oldnode = NULL;
         L->length--;
      }
   }
}

/*** Other operations ***/
void printList(ListRef L){  //prints a list on one line
   NodeRef oldcurr = L->current;
   L->current = L->first;
   while(!offEnd(L)){
      printf("%ld ",L->current->data);
      L->current = L->current->next;
   }
   printf("\n");
   L->current = oldcurr;
   oldcurr = NULL;
}

void printSort(ListRef L){        //prints a list in sorted order on one line
   NodeRef oldcurr = L->current;  //uses insertion sort after data is put into an array
   L->current = L->first;
   long bookarray[L->length];
   for(int i = 0; i<L->length; i++){
      bookarray[i] = L->current->data;
      L->current = L->current->next;
   }
   L->current = oldcurr;

   for(int i = 1; i<L->length; i++){
      int slot = i;
      long copy = bookarray[i];
      for(;slot > 0; --slot){
         if(copy > bookarray[slot-1])
            break;
         bookarray[slot] = bookarray[slot-1];
      }
      bookarray[slot] = copy;
   }
   
   for(int i = 0; i<L->length; i++){
      printf("%ld ", bookarray[i]);
   }
   printf("\n");
}















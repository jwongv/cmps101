//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439


#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>

typedef struct list *listRef;
typedef struct node *nodeRef;

typedef struct node{
   int vertex;
   nodeRef next;
   nodeRef prev;
} nodeType;

typedef struct list {
   nodeRef first;
   nodeRef last;
   int length;
   int color;
   int parent;
   int distance;
} listType;



/*** Constructors ***/
listRef newList(void);

void freeList(listRef L);

/*** Access Functions ***/
int isEmpty(listRef L);

int getFirst(listRef L);

int getLast(listRef L);


/*** Manipulation Procedures ***/

void insert(listRef L, int vertex);

void deleteFirst(listRef L);

void deleteLast(listRef L);







#endif

//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439

#ifndef __BOOKLIST_H__
#define __BOOKLIST_H__

#include "List.h"

typedef struct bookNode *bookNodeRef;
typedef struct bookList *bookListRef;

typedef struct bookNode {
   long data;
   ListRef copurchases;
   bookNodeRef next;
   bookNodeRef prev;
} bookNodeType;


typedef struct bookList {
   bookNodeRef first;
   bookNodeRef last;
} bookListType;
 
/*** Constructors ***/
bookListRef newBookList(void);

/*** Access Functions ***/
int isBEmpty(bookListRef B);

int inList(bookListRef B, long data);

bookNodeRef findBook(bookListRef B, long data);


/*** Manipulation Proceures ***/
void insertBook(bookListRef B, long data);



#endif

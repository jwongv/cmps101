//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439

#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>

typedef struct List *ListRef;
typedef struct Node *NodeRef;

typedef struct Node {
   long data;
   int count;
   NodeRef next;
   NodeRef prev;
} NodeType;

typedef struct List {
   NodeRef first;
   NodeRef last;
   NodeRef current;
   int length;
} ListType;


/*** Constructors ***/
ListRef newList(void);

void freeList(ListRef L);

/*** Access functions ***/
int isEmpty(ListRef L); // returns true is list is empty else returns false.

int offEnd(ListRef L); // returns true is current == NULL

int atFirst(ListRef L); // returns true if current == first and !offEnd()

int atLast(ListRef L); // returns true if current == last and !offEnd()

long getFirst(ListRef L); // return the first element; pre: !isEmpty()

long getLast(ListRef L); // return the last element; pre: !isEmpty()

long getCurrent(ListRef L); // return the current element pre: !offEnd()

int getLength(ListRef L); // return the length of the list

int getCount(NodeRef N);

int equals (ListRef A, ListRef B); // return true iff the two lists have the same keys
                                   // in the same order
int inCList(ListRef L, long data);

NodeRef highestCount(ListRef L, ListRef cust);

NodeRef findCBook(ListRef L, long data);

/*** Manipulation procedures ***/
void makeEmpty(ListRef L); // make the list empty. Post: isEmpty()

void moveFirst(ListRef L); // set current marker to the first element in the list
                           // Pre: !isEmpty(); Post: !offEnd()
void moveLast(ListRef L); // set current marker to the last element in the list
                          // Pre: !isEmpty(); Post: !offEnd()
void movePrev(ListRef L); // set current marker one step backward.
                          // Pre: !offEnd(); Post: offEnd() only if atFirst() was true
void moveNext(ListRef L); // set current marker one step forward.
                          // Pre: !offEnd(); Post: offEnd() only if atLast() was true
void upCount(NodeRef N);

void insertBeforeFirst(ListRef L, long data); // Inserts new element before first
                                              // Post: !isEmpty()
void insertAfterLast(ListRef L, long data); // Inserts new element after last one
                                            // Post: !isEmpty()
void insertBeforeCurrent(ListRef L, long data); // Inserts new element before current one
                                                // Pre: !offEnd(); Post: !isEmpty(), !offEnd()
void insertAfterCurrent(ListRef L, long data); // Inserts new element after current one
                                               // Pre: !offEnd(); Post: !isEmpty(), !offEnd()
void deleteFirst(ListRef L); // delete the first element. Pre: !isEmpty()

void deleteLast(ListRef L); // delete the last element. Pre: !isEmpty()

void deleteCurrent(ListRef L); // delete the current element.
                               // Pre: !isEmpty(), !offEnd(); Post: offEnd()

/*** Other operations ***/
void printList(ListRef L);

void printSort(ListRef L);

ListRef copyList(ListRef L);

#endif


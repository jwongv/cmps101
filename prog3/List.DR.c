//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439


#include <stdio.h>
#include "List.h"

int main (int argc, char **argv){
   ListRef list = newList();

   //testing isEmpty() and offEnd();
   printf("New list created. Testing isEmpty() and offEnd()\n");
   if(isEmpty(list))
      printf("List is empty\n");
   if(offEnd(list))
      printf("List is off end\n");
  
   //testing printList(); 
   printf("Adding 1 2 3 4 to list and printing whole list. The output should be 1 2 3 4\n");
   insertAfterLast(list, 1);
   insertAfterLast(list, 2);
   insertAfterLast(list, 3);
   insertAfterLast(list, 4);
   printList(list);

   //testing getFirst() and getLast()
   printf("Printing first and last. Output should be 1 and 4\n");
   printf("%ld\n%ld\n", getFirst(list), getLast(list));

   //testing moveNext(), movePrev(), and getCurrent()
   printf("Printing current. Output should be same as last, 4\n");
   printf("%ld\n", getCurrent(list));
   printf("Moving current back twice and foward once. Printing after each move, output should be 3 2 3\n");
   movePrev(list);
   printf("%ld\n", getCurrent(list));
   movePrev(list);
   printf("%ld\n", getCurrent(list));
   moveNext(list);
   printf("%ld\n", getCurrent(list));

   //testing moveFirst(), moveLast(), atFirst() and atLast()
   printf("Moving current to first then last. Checks if current is first or last. Output should be 1 and 4\n");
   moveFirst(list);
   printf("%ld\n", getCurrent(list));
   if(atFirst(list))
      printf("Yes, currently at first\n");
   moveLast(list);
   printf("%ld\n", getCurrent(list));
   if(atLast(list))
      printf("Yes, currently at last\n");

   //testing all inserts
   printf("Moving current to 3\n");
   moveFirst(list);
   moveNext(list);
   moveNext(list);
   printf("Inserting 5 AFTER current, output should be 1 2 3 5 4\n");
   insertAfterCurrent(list, 5);
   printList(list);
   printf("Inserting 7 BEFORE current, output should be 1 2 7 3 5 4\n");
   insertBeforeCurrent(list, 7);
   printList(list);
   printf("Inserting 6 BEFORE first, output should be 6 1 2 7 3 5 4\n");
   insertBeforeFirst(list, 6);
   printList(list);
   printf("Inserting 8 AFTER last, output should be 6 1 2 7 3 5 4 8\n");
   insertAfterLast(list, 8);
   printList(list);

   //testing sorted printing
   printf("Testing sorted printing. Output should be 1 2 3 4 5 6 7 8\n");
   printSort(list);

   //testing getLength()
   printf("Printing length of list. Output should be 8\n");
   printf("%d\n", getLength(list));

   //testing deletion
   printf("Deleting the first node. Output should be 1 2 7 3 5 4 8\n");
   deleteFirst(list);
   printList(list);

   printf("Deleting the last node. Output should be 1 2 7 3 5 4\n");
   deleteLast(list);
   printList(list);

   printf("Setting current to 3\nDeleting current node. Output should be 1 2 3 5 4\n");
   moveFirst(list);
   moveNext(list);
   moveNext(list);
   deleteCurrent(list);
   printList(list);

   insertAfterLast(list, 5);
   insertAfterLast(list, 5);
   insertAfterLast(list, 5);
   insertAfterLast(list, 5);
   insertAfterLast(list, 5);


   printf("Inserting 5 multiple times to see if count increases\n");
   printf("%d\n",getCount(findCBook(list, 5)));


   //testing emptyList()
   printf("Emptying list. There should be blank or no output\n");
   makeEmpty(list);
   printList(list);
   if(isEmpty(list))
      printf("Yes the list is empty\n");

   freeList(list);

   printf("Done testing! =)\n");



   return 0;
}

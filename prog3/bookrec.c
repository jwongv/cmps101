//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439

#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "hash.h"
#include "booklist.h"

int main (int argc, char **argv){
   int EXIT_STATUS = 0;
   
   FILE *info = fopen (argv[1], "r");  //open file for scanning
   if(info == NULL){  //check for valid filename, if not exit with status 1
      fflush(NULL);
      fprintf(stderr,"Invalid file name!\n");
      fflush(NULL);
      EXIT_STATUS = 1;
      exit(EXIT_STATUS);
   }

   long numcustomers;  //variable for # of customers
   long numpurchases;  //variable for # of purchases
   long hashsize;
   fscanf(info, "%ld", &numcustomers);  //scan in first number as # customers
   fscanf(info, "%ld", &numpurchases);  //scan in next number as # customers
   fscanf(info, "%ld", &hashsize);

   hashRef bookhash = newHash(hashsize);

   ListRef customers[numcustomers+1];  //create array that holds list for each customer

   for(int i = 1; i<numcustomers+1; i++){  //create a list for each customer
      customers[i] = newList();
   }

   long bookid = 0;  //variables for custid and bookid
   long custid = 0;
   int printrecbool = 0;
   int check = 0;    //variable to check for EOF

   fscanf(info, "%ld %ld %d", &custid, &bookid, &printrecbool);  //initial scan of custID and bookID
   while(check != EOF){  //loop until we reach end of file
      insertAfterLast(customers[custid], bookid);  //add bookID to appropriate customer list
      insertBookList(bookhash, bookid);            //inserts book into the hash

      for(NodeRef current = customers[custid]->first; current != NULL; current = current->next){
         if(current->data != bookid){
            int index = hashKey(bookhash, bookid);
            bookNodeRef temp = findBook(bookhash->purchasedBooks[index], bookid);
            insertAfterLast(temp->copurchases, current->data);

            index = hashKey(bookhash, current->data);
            temp = findBook(bookhash->purchasedBooks[index], current->data);
            insertAfterLast(temp->copurchases, bookid);
         }
      }


      if(printrecbool){
         int index = hashKey(bookhash, bookid);
         bookNodeRef temp = findBook(bookhash->purchasedBooks[index], bookid);
         NodeRef mostfreq = highestCount(temp->copurchases, customers[custid]);
         printf("Customers buying book %ld also purchased book %ld\n", bookid, mostfreq->data);
      }
      check = fscanf(info, "%ld %ld %d", &custid, &bookid, &printrecbool);  //scan in next custID and bookID
   }



   fclose(info);

   return EXIT_STATUS;
}

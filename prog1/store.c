//Jacky Wong
//jagwong@ucsc.edu
//ID:1281439

#include <stdio.h>
#include <stdlib.h>
#include "List.h"

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
   fscanf(info, "%ld", &numcustomers);  //scan in first number as # customers
   fscanf(info, "%ld", &numpurchases);  //scan in next number as # customers

   ListRef customers[numcustomers+1];  //create array that holds list for each customer

   for(int i = 1; i<numcustomers+1; i++){  //create a list for each customer
      customers[i] = newList();
   }

   long bookid = 0;  //variables for custid and bookid
   long custid = 0;
   int check = 0;    //variable to check for EOF

   fscanf(info, "%ld %ld", &custid, &bookid);  //initial scan of custID and bookID
   while(check != EOF){  //loop until we reach end of file
      insertAfterLast(customers[custid], bookid);  //add bookID to appropriate customer list
      check = fscanf(info, "%ld %ld", &custid, &bookid);  //scan in next custID and bookID
   }

   printf("Customer#       books purchased\n"); //print header for the output
   for(long i = 1; i<numcustomers+1; i++){      //loop to print all the custIDs and their lists
      printf("%ld       ", i);                  //print custID and 7 spaces
      printSort(customers[i]);                  //print the list for the current customer in sorted order
      makeEmpty(customers[i]);                  //empty the current customers list
      freeList(customers[i]);                   //free the list
   }

   fclose(info);

   return EXIT_STATUS;
}

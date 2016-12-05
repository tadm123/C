/* Program reads a file and prints the date in this form: September 13, 2010
   allow the user to  enter date in either 9-13-2010 or 9/13/2010 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

   int m,d,y,item;
   float price= 0.0;

   FILE *fp;

   if((fp=fopen("asdf.txt","rb")) == NULL)
   {
       fprintf(stderr,"Cannot open file.\n");
        exit(EXIT_FAILURE);
   }

    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");

    while(fscanf(fp,"%d,%f,%d/%d/%d",&item,&price,&m,&d,&y) == 5)
        printf("%d\t\t$%7.2f\t%2d/%2d/%4d\n",item,price,m,d,y);


    return 0;
}


/*  asdf.txt:

    583,13.5,10/24/2005
    3912,599.99,7/27/2008     */


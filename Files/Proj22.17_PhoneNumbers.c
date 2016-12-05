/* This program reads a series of phone numbers from a file
   and displays them in a standard form.
   Standard form: (xxx) xxx-xxxx */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, int *argv[])
{
   int phone_num[10],i=0;
   char ch;
   FILE *fp;

   if(argc != 2)
   {
       fprintf("Wrong format, input the name of the file.\"))
       exit(EXIT_FAILURE);
   }
   if((fp=fopen(argv[1],"rb")) == NULL)
   {
       fprintf(stderr,"Couldn't open file %s","test.txt");
       exit(EXIT_FAILURE);
   }



   while((ch=getc(fp)) != EOF)
     {
         if(isdigit(ch)) //or if(isdigit(ch))
         {
             phone_num[i]=ch;  //phone_number[0]= 6
                           // i++
             if(i == 9)
                {
                    printf("(%c%c%c) %c%c%c-%c%c%c%c\n",phone_num[0],phone_num[1],
                    phone_num[2],phone_num[3],phone_num[4],phone_num[5],
                    phone_num[6],phone_num[7],phone_num[8],phone_num[9]);

                    i=0;
                    continue;
                }
           i++;
         }

     }


    fclose(fp);
    return 0;
}

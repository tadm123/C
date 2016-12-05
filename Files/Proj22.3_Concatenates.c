/* This program "concatanates" any number of files
   by writing them to the standard output one after the other */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    int i;
    char ch;
    FILE *fp;

    if(argc == 1)
    {
        printf("Please enter a file name.\n");
        return 0;
    }

    for(i=1; i<argc; i++)
    {
        if ((fp=fopen(argv[i],"rb")) == NULL)
        {
            fprintf(stderr, "Couldn't open the file %s\n.",argv[i]);
            exit(EXIT_FAILURE);
        }


    while ((ch=getc(fp)) != EOF)        //gets the character
         putc(ch,stdout);

    }
    fclose(fp);

    return 0;
}

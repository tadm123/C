/* This program converts all letters in a file to upper-case
   and displays it in the screen (using stdout).
   The program should obtain the file from the command line */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void uppercase(const char *filename);

int main(int argc, char *argv[])
{

    if(argc == 1)
    {
        printf("Please enter a file name.\n");
        return 0;
    }

    uppercase(argv[1]);   //remember argv[] is an array of strings

    return 0;
}

void uppercase(const char *filename)
{
    char ch;
    FILE *fp= fopen(filename,"rb");

    if (fp == NULL)
    {
        fprintf(stderr,"Couldn't open the file");
        exit(EXIT_FAILURE);
    }

    while ((ch=getc(fp)) != EOF)        //gets the character
         putc(toupper(ch),stdout);

    fclose(fp);
}

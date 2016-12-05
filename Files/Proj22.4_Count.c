/* This program counts the number of characters, words
   and lines in a text file */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void num_characters(const char *filename,FILE *fp);
void num_words(const char *filename,FILE *fp);
void num_lines(const char *filename, FILE *fp);

int main(int argc, char *argv[])
{

    FILE *fp=fopen(argv[1],"rb");
    if(fp == NULL)
    {
        fprintf(stderr, "Couldn't open the file.\n");
        exit(EXIT_FAILURE);
    }

    num_characters(argv[1],fp);
    fseek(fp, 0L, SEEK_SET);            //going back to the start of the file
    num_words(argv[1],fp);
    fseek(fp, 0L, SEEK_SET);
    num_lines(argv[1],fp);
    fseek(fp, 0L, SEEK_SET);

    fclose(fp);

    return 0;
}

void num_characters(const char *filename,FILE *fp)
{
   int n=0;
   char ch;

    while ((ch=getc(fp)) != EOF)
       {
           putc(ch,stdout);
           n++;
       }

    printf("\n");
    printf("Number of Characters: %d.\n", n);
}

void num_words(const char *filename,FILE *fp)
{
   int n=1,m=0;
   char ch;

    while ((ch=getc(fp)) != EOF)
         {
            if(ch == ' ')
                n++;
            if(ch == '\n')
                m++;
         }
    m -= 1;
    printf("Number of words %d.\n", n+m);
}

void num_lines(const char *filename, FILE *fp)
{
   int n=0;
   char ch;

    while ((ch=getc(fp)) != EOF)
         {
            if(ch == '\n')
                n++;
         }

     printf("Number of lines %d.\n", n);
}

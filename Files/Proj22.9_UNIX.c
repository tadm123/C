/* This program converts a Windows text file to UNIX text file
   usage: program file1 file2 */

#include <stdio.h>
#include <stdlib.h>

int compare_parts(const void *p, const void *q)
{
    return (*(int *)p - *(int *)q);
}

int main(int argc, char *argv[])
{
   FILE *fpin,*fpout;
   int ch;

   if(argc != 3)
   {
       fprintf(stderr,"Wrong format: convert file1 file2.\n");
       exit(EXIT_FAILURE);
   }

   if((fpin=fopen(argv[1],"rb")) == NULL)
   {
       fprintf(stderr,"Couldn't open file %s",argv[1]);
       exit(EXIT_FAILURE);
   }

   if((fpout=fopen(argv[2],"wb")) == NULL)
   {
       fprintf(stderr,"Couldn't open file %s",argv[2]);
       exit(EXIT_FAILURE);
   }

    while ((ch = fgetc(fpin)) != EOF)
    {
        if (ch == '\x0d')
            fputc('\x0a', fpout);
        else if (ch != '\x0a')
            fputc(ch, fpout);
    }

    fclose(fpin);
    fclose(fpout);
    return 0;
}

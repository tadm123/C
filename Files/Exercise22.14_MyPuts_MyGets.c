/* Program: Write your own version of 'fgets' and 'fputs' */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_fgets(char my_string[], int bytes, FILE *stream)
{

    char ch, *p;
    int i=0;


    while(strlen(my_string) < bytes-1)
        {
            ch=getc(stream);
            my_string[i++]=ch;
            if(ch == '\n' || ch == EOF)
                break;
        }

    my_string[--i]= '\0';

    return my_string;

}

char *my_fgets2(char *str, int n, FILE *stream)
{
    int ch, chars_read = 0;

    while (chars_read < n - 1 && (ch = getc(stream)) != EOF) {
        str[chars_read++] = ch;
        if (ch == '\n')
            break;
    }
    if (chars_read == 0 || ferror(stream))   //if there are not characters
        return NULL;

    str[chars_read] = '\0';
    return str;
}
int my_fputs(const char *my_string, FILE *stream)
{

    while(*my_string != '\0')
          if(putc(*my_string++,stream) == EOF)
            return EOF;

    return 0;

}
int my_fputs2(const char *s, FILE *stream)
{
    while (*s)                  //Equivalent to while(*s != '\0')
        if (putc(*s++, stream) == EOF)
            return EOF;

    return 0;
}

int main()
{

    char my_string[15];
    char *p;

    FILE *fp;

    if((fp = fopen("test.txt", "rb+")) == NULL)
    {
        fprintf(stderr,"Couldn't open the file");
        exit(EXIT_FAILURE);
    }

  /* Note that fgets doesn't open the file, this has to be done
     outside that function obviously, on the main */

    p=my_fgets(my_string, sizeof(my_string), fp);
    my_fputs(my_string,stdout);

    fseek(fp,0L,SEEK_CUR);      //moves to the beggining of the file

    my_fputs("Testing if writing works",fp);    //writing this into file


    fclose(fp);



    return 0;
}

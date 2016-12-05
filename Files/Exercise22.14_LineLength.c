/* Write the following function
   int line_length(const char *filename, int n);
   the function should return the length of line n. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LINE_LEN 500

int line_length(const char *filename, int n);
void skip_line(char fp);

int line_length2(const char *filename, int n)
{

    FILE *fp;
    char line[MAX_LINE_LEN + 1];
    int line_num;

    if ((fp = fopen(filename, "r")) != NULL)
    {
        line_num = 1;

        while (fgets(line, sizeof(line), fp) != NULL)
        {
            if (line_num == n)
                return count_length(line);  //this goes up to '\n'
            ++line_num;
        }
        fclose(fp);
     }
    return 0;

}

/* Counts the length of string s, ignoring new line chars */
int count_length(const char *s)
{
    int n = 0;
    while (*s++) {
        if (*s != '\n')
            ++n;
    }
    return n;
}

int main()
{


  printf("%d",line_length("test.txt",3));

    return 0;
}

int line_length(const char *filename, int n)
{
    char ch;
    int i,length=0;

    FILE *fp;

    if((fp= fopen(filename, "r")) == NULL)
        exit(EXIT_FAILURE);


   for(i=1;i<n;i++)
       while(getc(fp) != '\n' );     //skips lines


    while(ch=fgetc(fp) != '\n' && ch != EOF)
        length++;

    fclose(fp);

    return length;
}

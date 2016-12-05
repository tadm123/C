#include <stdio.h>

/* (a) Skips white space before beginning to store characters*/
int read_line(char str[], int n)
{
    int ch, i=0;
    while ((ch=getchar()) != '\n')
    {
        if (i==0 && isspace(ch))
            ;
        else if (i<n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

/*(b) Have it stop reading at the first white-space char */
int read_line1(char str[], int n)
{
    int ch, i=0;
    while ((ch=getchar()) != '\n')
    {
        if(isspace(ch))
            break;
        else if(i<n)
            str[i++]=ch;
    }
    str[i++] ='\0';
    return i;
}

/*(c)Have it stop reading at the first new-line chars
     then store the new-line char in the string */
int read_line2(char str[], int n)
{
    int ch, i=0;
    while((ch=getchar()) != '\n')
        if (i<n)
            str[i++] = ch;

    str[i++]='\n';
    str[i]= '\0';

    return i;
}

int main()
{
    char my_string[20]={0};

    read_line(my_string,sizeof(my_string)/sizeof(my_string[0]));

    printf("%s",my_string);

    return 0;
}

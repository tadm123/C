#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define N 50

bool is_palindrome_pointer(const char *message);

int main()
{
    char message[N] = {0};

    printf("Enter a word: ");

    read_line(message,N);

    printf("%s\n",is_palindrome_pointer(message)?
            "Palindrome":"Not a palindrome");

    return 0;
}

bool is_palindrome_pointer(const char *message)
{
    const char *p=message, *q=message;

    while(*q)
        q++;
    --q;

    while(p<q)
        if(*p++ != *q--)
             return false;

    return true;
}

int read_line(char str[], int n)
{
    int ch, i=0;
    while((ch=getchar()) != '\n')
        if(i<n)
            str[i++] = ch;
    str[i]='\0';
    return i;
}

/* This program capitalizes a string */

#include <stdio.h>

void capitalize(char str[])    //Using Subscripts
{
    int i=0;
    while(str[i] != '\0')
        str[i] = toupper(str[i++]);
}

void capitalize1(char *str)    //Using Pointers
{
    char *p=str;
    while(*p != '\0')
    {
        *p= toupper(*p);
        p++;
    }
}

int main()
{
    char my_string[]="Hello there.";

    capitalize(my_string);
    printf("%s",my_string);

    return 0;
}

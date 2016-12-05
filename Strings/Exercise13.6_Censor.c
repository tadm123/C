/* Replaces in a word "foo" by "xxx" letters */

#include <stdio.h>

void censor_subs(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i]=='f' && str[i+1]=='o' && str[i+2]=='o')
            str[i] = str[i+1] = str[i+2] = 'x';

        printf("%c",str[i++]);
    }
}

void censor_ptr(char *str)
{
    char *p = str;
    while(*p)
    {
        if(*p=='f' && *(p+1)=='o' && *(p+2)=='o')
            *p = *(p+1) = *(p+2) = 'x';

        printf("%c",*p++);
    }
}

int main()
{
    char a[]= "food food";
    censor_ptr(a);

    return 0;
}

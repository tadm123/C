#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>


bool palindrome_subs(char a[],int len)
{
    int i;
    for(i=0;i<len;i++)
        if(a[i] != a[len - i-1])  //a[0] == a[10]
             return false;

    return true;
}

bool palindrome_ptr(char a[],int len)
{
    char *p=a,*q=a;

    while(*q)     //moving pointer to NULL character
        q++;

    for(p,--q; q >= p; p++,q--)
        if(*p != *q)
            return false;

    return true;
}

int main()
{
    int length=0;
    char a[50]={0}, ch;
    bool pal=false;

    printf("Enter a message: ");

    while((ch=getchar()) != '\n')
    {
        ch = toupper(ch);
        if(ch >= 'A' && ch <= 'Z')
            {
                a[length] = ch;
                length++;
            }
    }

    pal = palindrome_subs(a,length);
    printf("Using subscripts:\n");
    printf("%s\n\n", pal ? "Palindrome":"Not a Palindrome");

    printf("Using pointers:\n");
    pal = palindrome_ptr(a,length);
    printf("%s\n", pal ? "Palindrome":"Not a Palindrome");

    return 0;
}

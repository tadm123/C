#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch,array[50]={0};
    int length,i;

    for(length=0 ;(ch=getchar()) != '\n'; length++) //fills array
        array[length]=ch;

    for(i=0; i<length;i++)
    {
        ch=toupper(array[i]);

        switch(ch)
        {
        case 'A': ch = '4';
                    break;
        case 'B': ch = '8';
                    break;
        case 'E': ch = '3';
                    break;
        case 'I': ch = '1';
                    break;
        case 'O': ch = '0';
                    break;
        case 'S': ch = '5';
                    break;
        default: break;
        }

        printf("%c",ch);
    }
    printf("!!!!!!!!!!");   //appends exclamation marks

    return 0;
}

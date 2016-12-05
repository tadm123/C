#include <stdio.h>
#include <ctype.h>

int main()
{
    int w=0,sum=0;
    char ch;

    printf("Enter a word: ");
    while((ch=getchar()) != '\n')
    {
        switch(toupper(ch))
        {
            case 'A':case 'E':case 'I':case 'L': case 'N':
            case 'O':case 'R':case 'S':case 'T':case 'U':
                w=1;
                break;
            case 'D':case 'G':
                w=2;
                break;
            case 'B':case 'C':case 'M': case 'P':
                w=3;
                break;
            case 'F':case 'H':case 'V': case 'W': case 'Y':
                w=4;
                break;
            case 'K': w=5;
                break;
            case 'J':case 'X': w=8;
                break;
            case 'Q': case 'Z': w=10;
                break;
            default: continue;
        }
    sum += w;
    }
    printf("Scrabble value: %d",sum);

    return 0;
}

/* Converting a letter to a number */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch, a;

    printf("Enter a word: ");

    while ((ch = getchar()) != '\n')
    {
        switch (toupper(ch))
        {
            case 'A': case 'B':case 'C':
                a='2';
                break;
            case 'D': case 'E': case 'F':
                a='3';
                break;
            case 'G': case 'H': case 'I':
                a='4';
                break;
            case 'J': case 'K': case 'L':
                a='5';
                break;
            case 'M': case 'N': case 'O':
                a='6';
                break;
                case 'P': case 'R': case 'S':
                a='7';
                break;
            case 'T': case 'U': case 'V':
                a='8';
                break;
            case 'W': case 'X': case 'Y':
                a='9';
                break;
            default:
                a=ch;
        }

        printf("%c", a);
    }

 return 0;
}

#include <stdio.h>
#include "word.h"           //Hello there my friend

int read_char(void)     //function to avoid '\n' or '\t' chars when reading a character
{
    int ch = getchar();    //'H'

    return (ch == '\n'||ch == '\t' ? ' ' : ch );
}

void read_word(char *word, int len)  //len=21 (MAX_WORD_LEN+1)
{
    int ch, pos=0;

    while((ch=read_char()) == ' ')  //Skips white space   ...Hello
          ;
    while(ch != ' ' && ch !=EOF)    //if character is not ' '
    {
        if (pos<len)              //if(0<21)
            word[pos++]=ch;       //word[0]=ch;
        ch= read_char();
    }
    word[pos]= '\0';
    if (pos >(len-1))
            word[len]='*';      //21'st character
}

#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(void)
{
    char word[MAX_WORD_LEN+2];
    int word_len;

    clear_line();
    for(;;)
    {
        read_word(word, MAX_WORD_LEN+1);   //truncates word to 21 char... Also rewritres 'word' constantly
        word_len = strlen(word);
        if(word_len == 0)           //If it can't read word
        {
            flush_line();           //write contents on line buffer without justification
            return 0;               //terminates program
        }

        if(word_len + 1 > space_remainding())
        {
            write_line();
            clear_line();
        }
        add_word(word);
    }
}

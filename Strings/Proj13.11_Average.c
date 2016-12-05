#include <stdio.h>
#include <ctype.h>
#include <string.h>

double compute_average_word_length(const char *sentence)
{
    int i=1, len=0;

    len= strlen(sentence);

    for(;*sentence;sentence++)
        if(*sentence == ' ')
            i++;
    return (float)(len - i+ 1)/i;
}

int main()
{
    char sentence[20];
    printf("Enter a sentence: ");
    fgets(sentence,20,stdin);
    strtok(sentence, "\n");

    printf("%.2f", compute_average_word_length(sentence));

    return 0;
}

#include <stdio.h>
#include <string.h>

#define WORD_LEN 20


int main()
{
    char word[WORD_LEN+1],smallest[WORD_LEN+1],largest[WORD_LEN+1];

    for(;;)
    {
        printf("Enter a word: ");
        fgets(word,WORD_LEN+1,stdin);
        strtok(word, "\n");             //removes newline

        if (strlen(largest) < strlen(word))
            strcpy(largest,word);
        else if(strlen(smallest) > strlen(word))
            strcpy(smallest,word);

        if(strlen(word) == 4)          //if word is 4 characters
            break;                     //break out of loop
    }

    printf("Smallest: %s, Largest: %s", smallest,largest);
    return 0;
}

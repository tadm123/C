/* Counts the number of vowels in a string */

#include <stdio.h>
#include <ctype.h>

int compute_vowel_count(const char *sentence);
int main()
{
    char a[30];
    printf("Enter a word: ");
    fgets(a,30,stdin);
    strtok(a, "\n");
    printf("%d", compute_vowel_count(a));

    return 0;
}

int compute_vowel_count(const char *sentence)
{
    int total = 0;

    while(*sentence)
    {
        if(*sentence == 'a' || *sentence == 'e' || *sentence == 'i'
           ||*sentence == 'o' || *sentence == 'u')
                total++;
        sentence++;
    }
    return total;
}

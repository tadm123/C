#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
    int i, letter_count[26]={0};
    char ch;
    bool is_anagram=true;

    printf("Enter first word: ");
    for(i=0; (ch=getchar()) != '\n'; i++)
        letter_count[toupper(ch)-'A']++;

    printf("Enter second word: ");
    for(i=0; (ch=getchar()) != '\n'; i++)
        letter_count[toupper(ch)-'A']--;

    for(i=0;i<26;i++)
        if(letter_count[i] != 0)
        {
            is_anagram=false;
            break;
        }

    printf("The words are: ");
    if(is_anagram)
    printf("Anagrams.");
    else printf("Not Anagrams.");

    return 0;
}

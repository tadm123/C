#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main()
{
    int first_word[26] = {0},second_word[26]={0};

    read_word(first_word);
    read_word(second_word);

    if(equal_array(first_word,second_word))
        printf("Anagram");
    else printf("Not Anagram");

    return 0;

}

void read_word(int counts[26])
{
    int i;
    char ch;
    printf("Enter a word: ");
    for (i=0; (ch=getchar()) != '\n'; i++)
        counts[toupper(ch)-'A']++;
}

bool equal_array(int counts1[26], int counts2[26])
{
    int i;
    bool is_anagram= true;
    for(i=0;i<26;i++)
    {
        counts1[i]=counts1[i] - counts2[i];
        if(counts1[i] != 0)
        {
            is_anagram= false;
            break;
        }
    }
    return is_anagram;
}


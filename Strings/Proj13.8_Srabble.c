#include <stdio.h>
#include <ctype.h>

int compute_scrabble_value(const char *word);
int main()
{
    char a[30];
    printf("Enter a word: ");
    fgets(a,30,stdin);
    strtok(a, "\n");

    printf("Scrabble value: %d", compute_scrabble_value(a));

    return 0;
}

int compute_scrabble_value(const char *word)
{
    int total=0;
    int scrabble_value[26] = {
                    1,3,3,2,1,4,2,4,1,8,5,1,3,
                    1,1,3,10,1,1,1,1,4,4,8,4,10};
    while(*word)
    {
        total += scrabble_value[toupper(*word) - 'A'];
        word++;
    }
    return total;
}

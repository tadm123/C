/* This Program prints the average word length in a sentence */


#include <ctype.h>
#include <stdio.h>

int main()
{

    char ch;
    int sum=1, word_len=0;
    float avg=0.0;

    printf("Enter a sentence: ");
    while((ch=getchar()) != '\n')
        if (ch == ' ')
            sum += 1;
        else if (ch != ' ')
            word_len +=1;
        avg += word_len;

    avg /= sum;
    printf("Average word len: %.1f", avg);


    return 0;
}

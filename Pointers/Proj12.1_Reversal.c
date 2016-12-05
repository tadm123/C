#include <stdio.h>

/* Using Subscripts*/

int main()
{
    int length, *p, i;
    char array[50]={0};

    printf("Enter a message: ");
    for(length=0;(array[length]= getchar()) != '\n'; length++)
        ;
    printf("Reversal is: ");

    for(i= length-1; i >= 0; i--)
        printf("%c",array[i]);

    return 0;
}

/* Using Pointers */
/*
int main()
{
    int length = 0;
    char *p;
    char array[50]={0};

    printf("Enter a message: ");

    for(p=array; (*p=getchar()) != '\n'; p++)
        length++;

    printf("Reversal is : ");
    for(p=array+ (length-1); p >= array; p--)
        printf("%c", *p);

    return 0;
}
*/

#include <stdio.h>

int main()
{
    int n,first,last;

    printf("Enter a two-digit number: ");
    scanf("%d",&n);
    first =  n/10;
    last = n%10;
    printf("The reversal is %d%d",last,first);

    return 0;
}

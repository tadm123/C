#include <stdio.h>

int main()
{
    int n,first,middle,last;

    printf("Enter a three-digit number: ");
    scanf("%d",&n);

    first =  n/10;
    middle = first%10;
    first = (n/10)/10;
    last = n%10;
    printf("The reversal is %d%d%d",last,middle,first);

    return 0;
}

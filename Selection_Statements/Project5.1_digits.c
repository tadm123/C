#include <stdio.h>

int main()
{
    int num=0;
    int dig=0;

    printf("Enter a number: ");
    scanf("%d",&num);

    if(num > 0 && num < 10)
        dig=1;
    else if(num >= 10 && num <100)
        dig=2;
    else if (num >= 100 && num < 1000)
        dig=3;
    else if (num >= 1000 && num < 10000)
        dig=4;
    else if (num >= 10000 && num < 100000)
        dig=5;
    else if (num >= 100000 && num < 1000000)
        dig=6;

    printf("The number %d has %d digits.",num,dig);


    return 0;
}

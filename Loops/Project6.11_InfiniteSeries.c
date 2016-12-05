#include <stdio.h>


float factorial(float num)
{
    if (num ==0) return 1;
    else return num *factorial(num-1);
}

int main()
{
    int i,n;
    float sum=1.0;

    printf("Type a number: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
        sum += 1.0f/factorial(i);

    printf("e: %.5f", sum);


    return 0;
}

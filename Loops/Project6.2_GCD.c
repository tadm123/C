/* Program finds the greatest common divisor (GCD) */

#include <stdio.h>

int gcd(int m,int n)
{
    int remainder=0;
    while(n!=0)
    {
        remainder= m%n;
        m=n;
        n=remainder;
    }
    return m;
}


int main()
{

    int num1,num2;

    printf("Enter two integers: ");
    scanf("%d %d",&num1,&num2);
    printf("Greatest common divisor: %d",gcd(num1,num2));

    return 0;
}

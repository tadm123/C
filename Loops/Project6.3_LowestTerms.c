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
    int num,den;

    printf("Enter a fraction: ");
    scanf("%d/%d",&num,&den);

    printf("In lowest terms: %d/%d", num/gcd(num,den),
           den/gcd(num,den));

    return 0;
}

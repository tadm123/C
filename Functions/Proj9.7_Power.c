#include <stdio.h>

int power(int x, int n)
{
    if(n == 0) return 1;
    if(n % 2 == 0)
    {
        int i = power(x,n/2);
        return i*i;
    }
    else
        return x*power(x , n-1);
}

int main()
{
    int x,n;
    printf("Enter a value and an exponent: ");
    scanf("%d %d", &x, &n);
    printf("%d to the %d = %d", x,n, power(x,n));
    return 0;
}

#include <stdio.h>

void reduce(int numerator, int denominator,
            int *reduced_numerator, int *reduced_denominator)
{
    int remainder =0;
    int m= numerator, n = denominator;

    while(n != 0)
    {
        remainder = m % n;
        m = n;
        n = remainder;
    }
    *reduced_numerator = numerator/m;
    *reduced_denominator = denominator/m;
}

int main()
{
    int m,n,r_m,r_n;

    printf("Enter a fraction (x/x): ");
    scanf("%d/%d",&m,&n);

    reduce(m,n,&r_m,&r_n);
    printf("In lowest form: %d/%d", r_m,r_n);

    return 0;
}

#include <stdio.h>

struct fraction{
        int numerator, denominator;
        };

int find_gcd(struct fraction s1);

int main()
{
    struct fraction d1;
    int gcd;

    d1.numerator= 20;
    d1.denominator = 100;
    printf("Fraction: %d/%d\n", d1.numerator, d1.denominator);

    gcd = find_gcd(d1);

    printf("In lowest terms: %d/%d", d1.numerator/gcd,
                                    d1.denominator/gcd);

    return 0;
}

int find_gcd(struct fraction s1)
{
    int remainder = 0;
    while(s1.denominator != 0)
    {
        remainder = s1.numerator % s1.denominator;
        s1.numerator = s1.denominator;
        s1.denominator = remainder;
    }
    return s1.numerator;
}

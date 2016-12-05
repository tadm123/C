/* Adds fractions */

#include <stdio.h>

struct fraction{
    int numerator,denominator;
    };

int find_gcd(int n1, int n2);
struct fraction add_fractions(struct fraction s1,
                              struct fraction s2);

int main()
{
    struct fraction d1,d2,d3;
    d1.numerator = 1;
    d1.denominator = 2;
    d2.numerator = 4;
    d2.denominator = 10;

    d3 = add_fractions(d1,d2);
    printf("Total: %d/%d", d3.numerator, d3.denominator);

    return 0;
}



struct fraction add_fractions(struct fraction s1,
                              struct fraction s2)
{
    int gcd;
    int den = s1.denominator * s2.denominator;
    struct fraction s3;

    s3.numerator = ((den/s1.denominator)* s1.numerator) +
                   ((den/s2.denominator) * s2.numerator);

    gcd = find_gcd(s3.numerator, den);
    s3.numerator /= gcd;
    s3.denominator = den/gcd;

    return s3;
}
int find_gcd(int n1, int n2)
{
    int temp;
    while (n1 != 0)
    {
        temp = n2 % n1;
        n2 = n1;
        n1 = temp;
    }
    return n2;
}

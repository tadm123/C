/* Counts repeated digits */


#include <stdio.h>


int main()
{
    int digits_seen[10]= {0};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld",&n); //4441

    while (n>0)
    {
        digit = n % 10;
        digits_seen[digit]++;
        n /= 10;
    }

    printf("Repeated digit(s): ");
    for (; n < 10; n++)
        if (digits_seen[n] > 1)
            printf("%ld ", n);



    return 0;
}

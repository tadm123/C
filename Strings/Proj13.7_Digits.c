#include <stdio.h>

int main()
{
    int number, tens, ones;

    char *tens_pt[8] = {"Twenty","Thirty","Forty","Fifty",
                        "Sixty","Seventy","Eighty","Ninety"};

    char *ones_pt[9] = {"One","Two","Three","Four","Five",
                        "Six","Seven","Eight","Nine"};

    char *tenOne_pt[10]={"Ten","Eleven","Twelve","Thirteen",
                         "Fourteen","Fifteen","Sixteen",
                         "Seventeen","Eighteen","Nineteen"};

    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    tens = number / 10;
    ones = number % 10;

    if(tens == 1)
        printf("%s", tenOne_pt[ones]);
    else if(tens == 0)
        printf("%s",ones_pt[ones-1]);
    else
        printf("%s-%s", tens_pt[tens-2], ones_pt[ones-1]);

    return 0;
}

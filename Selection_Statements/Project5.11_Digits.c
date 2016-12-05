#include <stdio.h>

void print_ones(int n)  //a single digit
{
    switch(n)
        {
            case(1):printf("One");
                    break;
            case(2):printf("Two");
                    break;
            case(3):printf("Three");
                    break;
            case(4):printf("Four");
                    break;
            case(5):printf("Five");
                    break;
            case(6):printf("Six");
                    break;
            case(7):printf("Seven");
                    break;
            case(8):printf("Eight");
                    break;
            case(9):printf("Nine");
                    break;
        }
}

void print_tens1(int n)
{
    switch(n)
        {
            case(0):printf("Ten");
                    break;
            case(1):printf("Eleven");
                    break;
            case(2):printf("Twelve");
                    break;
            case(3):printf("Thirteen");
                    break;
            case(4):printf("Fourteen");
                    break;
            case(5):printf("Fifteen");
                    break;
            case(6):printf("Sixteen");
                    break;
            case(7):printf("Seventeen");
                    break;
            case(8):printf("Eighteen");
                    break;
            case(9):printf("Nineteen");
                    break;
        }
}

void print_tens2(int n)
{
    switch(n)
        {
            case(1):printf("Ten");
                    break;
            case(2):printf("Twenty-");
                    break;
            case(3):printf("Thirty-");
                    break;
            case(4):printf("Fourty-");
                    break;
            case(5):printf("Fifty-");
                    break;
            case(6):printf("Sixty-");
                    break;
            case(7):printf("Seventy-");
                    break;
            case(8):printf("Eighty-");
                    break;
            case(9):printf("Ninety-");
                    break;
        }
}

int main()
{

    int num,ones,tens;

    printf("Enter a two-digit number: ");  //56
    scanf("%d",&num);

    ones = num % 10;
    tens = num / 10;

    if (num > 0 && num < 10)    //just 1 digit
        print_ones(ones);
    else if (num >=10 && num <20)
        print_tens1(ones);
    else
    {
        print_tens2(tens);
        print_ones(ones);
    }

    return 0;
}

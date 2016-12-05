#include <stdio.h>

int main()
{
    int num=0,num1=0,num2=0,num3=0,num4=0,num5=0;


    printf("Enter a number between 0 and 32767: ");
    scanf("%d",&num);

    num5 = num % 8;
    num4 = (num / 8) % 8;
    num3 = ((num / 8) / 8) % 8;
    num2 = (((num / 8) / 8) / 8) % 8;
    num1 = ((((num / 8) / 8) / 8) / 8) % 8;
    printf("In octal your number is: %d%d%d%d%d",num1,
           num2,num3,num4,num5);

    return 0;
}

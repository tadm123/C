#include <stdio.h>

float calculates_max(float num[], int length)
{
    float max = 0.0;
    int i=0;

    for (i;i<length;i++)
        if (max < num[i])
            max = num[i];


    return max;
}

int main()
{
    float num=0.0;
    float a[50]={0.0};
    int i=0;

    for(;;)
    {
        printf("Enter a number: ");
        scanf("%f",&num);
        if (num == 0)
            break;
        a[i]=num;
        i++;

    }

    printf("Largest number entered was %.2f", calculates_max(a,i));
    return 0;
}

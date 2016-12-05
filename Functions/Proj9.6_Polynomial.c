#include <stdio.h>
#include <math.h>

float my_function(float x)
{
    return (3*pow(x,5)) + (2*pow(x,4)) - (5*pow(x,3))
            - pow(x,2) + (7*x)-6;
}

int main()
{
    float a = 0.0;
    printf("Enter a value for x:\n");
    scanf("%f",&a);

    printf("Answer: %.1f", my_function(a));

    return 0;
}

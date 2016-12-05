#include <stdio.h>

int main()
{
    int wind=0;

    printf("Enter a wind speed: ");
    scanf("%d",&wind);

    if (wind<1)
        printf("Calm");
    else if(wind>=1 && wind<=3)
        printf("Light air");
    else if(wind>=4 && wind<=27)
        printf("Breeze");
    else if(wind>=28 && wind<=47)
        printf("Gale");
    else if(wind>=48 && wind<=63)
        printf("Storm");
    else
        printf("Hurricane");

    return 0;
}

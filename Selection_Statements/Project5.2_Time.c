#include <stdio.h>

int main()
{

    int h,m;
    char c[]= "a.m";

    printf("Enter a 24-hour time: ");
    scanf("%d:%d",&h,&m);

    if (h > 12)
    {
        h -= 12;
        c[0]= 'p';
    }

    printf("Equivalent 12-hour time: %d:%d %s",h,m,c);

    return 0;
}

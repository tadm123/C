#include <stdio.h>


int main()
{

    int h=0,m=0;
    char t;
    printf("Enter a time (12-hour format): ");
    scanf("%2d:%2d %c",&h,&m,&t);

    if (toupper(t) == 'P')
        h +=12;

    printf("Equivalent 24-hour time: %d:%d",h,m);


    return 0;
}

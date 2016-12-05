#include <stdio.h>


int main()
{
    int m=0,d=0,y=0;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d",&m,&d,&y);
    printf("You entered the date %d/%d/%d", m,d,y);

    return 0;

}




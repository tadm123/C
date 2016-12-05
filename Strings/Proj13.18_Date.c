/* Formats a date */

#include <stdio.h>

char *my_month(int n)
{
    char *month[12]= {"January","February","March","April",
                      "May","June","July","August","September",
                      "October","November","December"};
    return month[--n];
}

int main()
{
    int m,d,y;

    printf("Enter a date (mm,dd,yyyy): ");
    scanf("%d/%d/%d", &m,&d,&y);

    printf("You entered the date %s %d, %d.", my_month(m),d,y);


    return 0;
}

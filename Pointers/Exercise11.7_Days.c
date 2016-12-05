#include <stdio.h>

void split_date(int day_of_year, int year, int *month, int *day);
void month_funct(int a);

int main()
{
    int days;
    int y=0,m=0,d=0;

    printf("Enter a day of the year (1-365): ");
    scanf("%d",&days);
    printf("Enter a year: ");
    scanf("%d",&y);

    split_date(days, y, &m, &d);

    printf("Year: %d, Month: ",y);
    month_funct(m);
    printf(", Day: %d",d);

    return 0;

}

void split_date(int day_of_year, int year, int *month, int *day)
{
    int i;
    for(i=0;i<day_of_year && i < 366; i++)
    {
        if (i % 31 == 0)
        {
            *month = *month + 1;
            *day =0;   //reset days
        }
        *day = *day + 1;
    }
}

void month_funct(int a)
{
    switch(a)
    {
        case 1: printf("January");
                break;
        case 2: printf("February");
                break;
        case 3: printf("March");
                break;
        case 4: printf("April");
                break;
        case 5: printf("May");
                break;
        case 6: printf("June");
                break;
        case 7: printf("July");
                break;
        case 8: printf("August");
                break;
        case 9: printf("September");
                break;
        case 10: printf("October");
                break;
        case 11: printf("November");
                break;
        case 12: printf("December");
                break;
        default:break;
    }
}

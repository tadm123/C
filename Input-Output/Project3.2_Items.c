#include <stdio.h>


int main()
{
    int m=0,d=0,y=0, item=0;
    float price = 0.0;

    printf("Enter item number: ");
    scanf("%d",&item);
    printf("Enter unit price: ");
    scanf("%f",&price);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d",&m,&d,&y);

    printf("\n");
    printf("Item\t\tUnit \t\tPurchase\n");
    printf("    \t\tPrice\t\tDate\n");
    printf("%d\t\t$%7.2f\t%d/%d/%d",item,price,m,d,y);

    return 0;

}

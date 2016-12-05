#include <stdio.h>


int main()
{

    int i,days,start;

    printf("Enter days of the month: ");
    scanf("%d",&days);

    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d",&start);   //start = 3

    for(i=1; i<start;i++)  //printing leading spaces
        printf("   ");

    for(i=1;i<=days;i++)
    {
        printf("%3d",i);
        if ((start +i - 1) % 7 ==0)
            printf("\n");
    }

    return 0;
}

#include <stdio.h>


int main()
{

    int i ,n;
    printf("Enter number of entries in the table: ");
    scanf("%d",&n);

    for(i=1;i <= n; i++)
    {
        printf("%10d%10d\n", i, i*i);
        if (i % 24 == 0)
        {
            printf("Press enter to continue...");
            while(getchar() != '\n')           //break if typed enter
                ;
        }


    }


    return 0;
}

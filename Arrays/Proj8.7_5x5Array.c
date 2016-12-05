# Prints the sum of rows and columns of a 5x5 array.

#include <stdio.h>

int main()
{

    char array[5][5]= {{0}};
    int i,j,sum_rows=0,sum_columns=0;

    for(i=0;i<5;i++)
    {
        printf("Enter row %d: ",i+1);
        for(j=0;j<5;j++)
             scanf("%d",&array[i][j]);
    }

    printf("Rows totals: ");
     for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            sum_rows += array[i][j];

        printf("%d ",sum_rows);
        sum_rows = 0;
    }
    printf("\n");


    printf("Columns totals: ");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
             sum_columns += array[j][i];

        printf("%d ",sum_columns);
        sum_columns = 0;
    }

    return 0;
}

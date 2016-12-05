#include <stdio.h>


int main()
{
    int num1,num2,num3,num4,num5,num6,num7,num8,num9,
        num10,num11,num12,num13,num14,num15,num16;

    int sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0,sum7=0,
        sum8=0,sum9=0,sum10=0;

    int i=0;


    printf("Enter the numbers from 1  to 16 in any order: ");


    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",&num1,
          &num2,&num3,&num4,&num5,&num6,&num7,&num8,&num9,&num10,&num11,
          &num12,&num13,&num14,&num15,&num16);

   printf("%2d %2d %2d %2d\n",num1,num2,num3,num4);
   printf("%2d %2d %2d %2d\n",num5,num6,num7,num8);
   printf("%2d %2d %2d %2d\n",num9,num10,num11,num12);
   printf("%2d %2d %2d %2d\n",num13,num14,num15,num16);

  //Sums of Rows
   sum1=num1+num2+num3+num4;
   sum2=num5+num6+num7+num8;
   sum3=num9+num10+num11+num12;
   sum4=num13+num14+num15+num16;

   //Sums of Columns
   sum5=num1+num5+num9+num13;
   sum6=num2+num6+num10+num14;
   sum7=num3+num7+num11+num15;
   sum8=num4+num8+num12+num16;

   //Sums of Diagonals
   sum9=num1+num6+num11+num16;
   sum10=num13+num10+num7+num4;

   printf("Rows sums: %d %d %d %d\n",sum1,sum2,sum3,sum4);
   printf("Columns sums: %d %d %d %d\n",sum5,sum6,sum7,sum8);
   printf("Diagonal sums: %d %d\n",sum9,sum10);

    return 0;

}

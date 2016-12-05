#include <stdio.h>

#define SIZE_ARRAY 7

void find_two_largest(int a[], int n, int *largest,int *second_largest)
{
    int i;
    *largest = *second_largest = a[0];  //largest = second_larbest =100

    for(i=1; i<n; i++)
    {
        if(a[i] > *largest)
            *largest = a[i];
        else if(a[i] > *second_largest && a[i] < *largest)
            *second_largest = a[i];
    }
}



int main()
{
    int array[SIZE_ARRAY] = {100,2,200,10,51,33,150};
    int larg=0,sec_larg=0, i=0;

    printf("Array: ");
    for(i=0; i < SIZE_ARRAY; i++)
        printf("%d ",array[i]);
    printf("\n");

    find_two_largest(array,SIZE_ARRAY,&larg,&sec_larg);


    printf("Largest: %d\nSecond largest : %d\n",larg,
                sec_larg);

    return 0;
}

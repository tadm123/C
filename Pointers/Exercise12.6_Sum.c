#include <stdio.h>

int sum_array(int a[], int n)
{
    int sum=0;
    int *p;
    for(p=a;p<a+n;p++)
        sum += *p;
    return sum;
}


int main()
{
    int array[]={2,4,100,4,-53,55,34,-5};

    printf("Sum: %d",sum_array(array,sizeof(array)/sizeof(array[0])));

    return 0;
}

#include <stdio.h>

void avg_sum(double a[], int n, double *avg, double *sum)
{
    int i=0;
    *sum = 0.0;
    for(;i<n;i++)
        *sum=*sum + a[i];
    *avg = *sum / n;
}

int main()
{
    double array[5]= {2,5,15,7,44};
    double a,b;
    avg_sum(array,5,&a,&b);    //passing the addresses of 'a' and 'b'
    printf("Average = %0.1f, Sum= %0.1f",a,b);

    return 0;

}

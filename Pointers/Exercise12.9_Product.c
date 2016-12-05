/* Finds the inner product of two arrays
   a[0]*b[0] + a[1]*b[1] + ... a[n-1]*b[n-1]  */

#include <stdio.h>

double inner_product(const double *a, const double *b, int n)
{
    double sum = 0;
    const double *a_ptr, *b_ptr;

    for(a_ptr=a,b_ptr=b;a_ptr<a+n && b_ptr< b+n; a_ptr++,b_ptr++)
    {
        printf("%.1f * %.1f = %.1f\n",*a_ptr,*b_ptr,
                                    *a_ptr * *b_ptr);
        sum += *a_ptr * *b_ptr;
    }
    return sum;
}
int main()
{
    const double a[5] = {1,2,3,4,5};
    const double b[5] = {1,2,3,4,5};

    printf("Inner product: %.1f",inner_product(a,b,5));

    return 0;
}

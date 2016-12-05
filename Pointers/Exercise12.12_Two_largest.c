#include <stdio.h>

void find_two_largest(const int *a, int n, int *largest,
                      int *second_largest)
{
    int i;
    *largest = *second_largest = *a;
    for(i=1; i<n; i++)
    {
        if(*(a+i) > *largest)
        {
            *second_largest = *largest;
            *largest = *(a+i);
        }
        else if (*(a+i) > *second_largest && *(a+i) < *largest)
            *second_largest = *(a+i);
    }
}

int main()
{
    int array[6]= {100,2,130,51,33,150};
    int larg,sec_larg;

    find_two_largest(array,6, &larg,&sec_larg);
    printf("Largest: %d\nSecond largest: %d", larg,sec_larg);

    return 0;
}

#include <stdio.h>
#include <stdbool.h>

#define SIZE(a) sizeof(a)/sizeof(a[0])

bool search(const int a[], int n, int key)
{
    const int *p;

    for(p=a; p<a+n; p++)
        if(*p == key)
            return true;
    return false;
}

int main()
{
    int array[]={1,4,42,2,55,10};
    int my_key = 2;

    printf("%s Array.", search(array,SIZE(array),my_key)?"In":"Not in");

    return 0;
}

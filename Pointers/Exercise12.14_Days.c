#include <stdio.h>
#include <stdbool.h>

bool search(const int a[], int n, int key)
{
    const int *p;

    for (p=a;p<a+n; p++)
        if(*p == key)
            return true;

    return false;
}

int main()
{
    int temperatures[7][24]= {[5][15]=31};
    int my_key = 31;

    printf("%s",search(temperatures[0], 7*24, my_key)?
            "Found":"Not Found");

    return 0;
}

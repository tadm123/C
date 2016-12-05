#include <stdio.h>

void swap(int *p, int *q)
{
    int temp = 0;    //to hold temporary value
    *p = *q;
    *q = temp;
}


int main()
{
    int i=2,j=4;
    printf("i = %d, j= %d\n",i,j);
    swap(&i,&j);
    printf("i = %d, j= %d",i,j);

    return 0;

}

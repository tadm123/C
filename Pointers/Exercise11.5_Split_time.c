#include <stdio.h>

void split_time(long total_sec, int *hr, int *min , int *sec)
{
    int temp = 0;
    *hr = total_sec/3600;
    temp = total_sec % 3600;
    *min = temp/60;
    *sec = temp %60;
}


int main()
{
    int long secs;
    int h,m,s;

    printf("Enter a number of seconds: ");
    scanf("%ld",&secs);

    split_time(secs, &h, &m, &s);
    printf("\nTime = %dh:%dm:%ds", h,m,s);

    return 0;
}

#include <stdio.h>


int main()
{
    int area=0,first=0,last=0;

    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d) %d-%d",&area,&first,&last);
    printf("You entered %d.%d.%d",area,first,last);

    return 0;

}

#include <stdio.h>


int main()
{
    int gsi=0,group=0,pub=0, item=0, dig=0;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d",&gsi,&group,&pub,&item,&dig);

    printf("GS1 prefix: %d\n",gsi);
    printf("Group identifier: %d\n",group);
    printf("Publisher code: %d\n",pub);
    printf("Item number: %d\n",item);
    printf("Check digit: %d\n",dig);


    return 0;

}

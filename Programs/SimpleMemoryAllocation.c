/* Simple program using dynamic arrays. When the array
   reaches 10 elements (n=10), it calles realloc to double
   the memory available */

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 10

int main()
{

    int *a;
    int max_size = INITIAL_SIZE;
    int length=0,i,num;

    a=calloc(max_size,sizeof(int));

    if(a == NULL)
    {
        printf("Not enough space. Allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Fill up your array (type any letter to exit): ");

    while(1)
    {
        if((scanf("%d", &num)) != 1)        //if it's not an integer (it returns 0) couldn't store it
            break;

        a[length]=num;
        length++;

        if((length % 10) == 0)
        {
            printf("Caling realloc to double size.\n");
            max_size *= 2;
            a= realloc(a,max_size * sizeof(int));
        }
    }

    printf("Your array is: \n");
        for(i=0; i< length; i++)
            printf("%d ", a[i]);

    free(a);

    return 0;

}


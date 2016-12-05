/* Inserts and removes items from a queque */

#include <stdio.h>
#include <stdlib.h>
#include "queque.h"

int main()
{
    Queque q1;

    q1=create();

    insert_item(q1,10);
    insert_item(q1,20);
    insert_item(q1,30);
    insert_item(q1,40);

    print (q1);

    printf("Last item:%d",get_last(q1));
    printf("\n");
    printf("First item:%d",get_first(q1));

    printf("\n");

    remove_item(q1);

    print(q1);

    printf("Is the Queque empty?: %s\n", is_empty(q1)?"Yes":"No");
    remove_item(q1);
    remove_item(q1);
    remove_item(q1);

    printf("Is the Queque empty?: %s", is_empty(q1)?"Yes":"No");

    destroy(q1);


    return 0;
}

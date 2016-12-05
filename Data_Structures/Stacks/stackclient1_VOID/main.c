#include <stdio.h>
#include "stackADT_type_VOID.h"

int main(void)
{
   Stack s1,s2;

   s1=create();
   s2=create();

   push(s1,"First");
   push(s1,"Second");
   push(s1,"Third");
   push(s1,"Fourth");

   print(s1);
   printf("Popping s1: %s\n",pop(s1));
   printf("Peeking the top value for s1: %s\n",peek(s1));
   printf("Length of s1: %d\n",length(s1));

   push(s2,"lol");
   push(s2,"asdf");

    print(s2);
    printf("Length of s2: %d\n",length(s2));

    return 0;
}

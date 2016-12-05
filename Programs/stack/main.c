#include <stdio.h>
#include <stdlib.h>
#include "proj1.h"


char ch;


int main(void)
{
    Stack s1;

    s1=create();

    while (true) {

        printf("Enter an RPN expression: ");

        while ((ch = getchar()) != EOF && ch != '\n')
            process_character(s1,ch);

    }

    destroy(s1);
    return 0;
}

/* processes a character to perform an operation on the stack
 */

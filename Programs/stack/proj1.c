#include <stdio.h>
#include <stdlib.h>
#include "proj1.h"

#define STACK_SIZE 100

struct stack_type{
    Item contents[STACK_SIZE];
    int top;
    };

/* external variables */


void stack_overflow(void)
{
        printf("Stack overflow");
        exit(EXIT_FAILURE);
}
void stack_underflow(void)
{
        printf("Stack underflow");
        exit(EXIT_FAILURE);
}

void make_empty(Stack s)
{
    s->top = 0;
}

bool is_empty(Stack s)
{
    return s->top == 0;
}

bool is_full(Stack s)
{
    return s->top == STACK_SIZE;
}

void push(Stack s,Item i)
{
    if (is_full(s))
        stack_overflow();

    s->contents[s->top++] = i;
}

Item pop(Stack s)
{
    if (is_empty(s))
        stack_underflow();

    return s->contents[--s->top];
}


Stack create(void)  //allocates memory for a stack
{
    Stack s= malloc(sizeof(struct stack_type));     //allocating space for the structure
    if(s==NULL)
        {
            printf("Error in create: stack could not be created.");
            exit(EXIT_FAILURE);
        }
    s->top=0;       //initializes stack to an 'empty' state (ex: top=0, no elements... top=1, it has now 1 element)
    return s;
}

void destroy(Stack s)
{
    free(s);
}

void process_character(Stack s,char ch)
{
    int operand1, operand2;

    switch(ch) {

        case '0':   push(s,0); break;
        case '1':   push(s,1); break;
        case '2':   push(s,2); break;
        case '3':   push(s,3); break;
        case '4':   push(s,4); break;
        case '5':   push(s,5); break;
        case '6':   push(s,6); break;
        case '7':   push(s,7); break;
        case '8':   push(s,8); break;
        case '9':   push(s,9); break;

        case '+':   push(s,pop(s) + pop(s));
                    break;

        case '-':   operand2 = pop(s);
                    operand1 = pop(s);
                    push(s,operand1 - operand2);
                    break;

        case '*':   push(s,pop(s) * pop(s));
                    break;

        case '/':   operand2 = pop(s);
                    operand1 = pop(s);
                    push(s,operand1 / operand2);
                    break;

        case '=':   printf("Value of expression: %d\n", pop(s));
                    break;

        case ' ':   break;

        default:    destroy(s);
                    exit(EXIT_FAILURE);


    }
}


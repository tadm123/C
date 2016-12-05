#include <stdio.h>
#include <stdlib.h>
#include "stackADT_type_VOID.h"

#define STACK_SIZE 100

struct stack_type {
        char *contents[STACK_SIZE];  // <- Using Arrays to store the contents of the stack
        int top;                    //not necessary to change from "int" to "Item" since it's just a counter
        int len;
        };

static void terminate(const char *message)
{
    printf("%s\n",message);
    exit(EXIT_FAILURE);
}

Stack create(void)  //allocates memory for a stack
{
    Stack s= malloc(sizeof(struct stack_type));     //allocating space for the structure
    if(s==NULL)
        terminate("Error in create: stack could not be created.");
    s->top=0;       //initializes stack to an 'empty' state (ex: top=0, no elements... top=1, it has now 1 element)
    s->len=0;
    return s;
}

void destroy(Stack s)
{
    free(s);
}

void make_empty(Stack s)
{
    s->top=0;
}

bool is_empty(Stack s)
{
    return s->top == 0;
}

bool is_full(Stack s)
{
    return s->top == STACK_SIZE;
}

void push(Stack s, void *p) //p is a string
{
    if(is_full(s))
        terminate("Error in push: stack is full.");
    s->len++;
    s->contents[s->top++]=p;
}

void *pop(Stack s)
{

   if(is_empty(s))
        terminate("Error in pop: stack is empty.");

    s->len--;
    return s->contents[--s->top];

}

void print(Stack s)
{
    int i;

    printf("Elements of stack are:\n");

    for(i=(s->top)-1;i>=0;i--)
        printf("%s\n",s->contents[i]);
}

void *peek(Stack s)
{
    return s->contents[s->top-1];
}

int length(Stack s)
{
    return s->len;
}

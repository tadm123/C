/*Implement a Stack Abstract Data Type (ADT) using Arrays */

#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

#define STACK_SIZE 100

struct stack_type {
        Item contents[STACK_SIZE];  // <- Using Arrays to store the contents of the stack
        int top;                    //not necessary to change from "int" to "Item" since it's just a counter
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

void push(Stack s, Item i)
{
    if(is_full(s))
        terminate("Error in push: stack is full.");
    s->contents[s->top++]=i;    //accesess the 'top' element from the structure
}

Item pop(Stack s)
{

   if(is_empty(s))
        terminate("Error in pop: stack is empty.");


    return s->contents[--s->top];

}

void print(Stack s)
{
    int i;

    printf("Elements of stack are:\n");

    for(i=(s->top)-1;i>=0;i--)
        printf("%d\n",s->contents[i]);
}

Item peek(Stack s)
{
    return s->contents[s->top-1];
}

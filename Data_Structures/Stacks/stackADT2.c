
/*Implement a Stack Abstract Data Type (ADT) using Dynamic Arrays */

#include <stdio.h>
#include <stdlib.h>
#include "stackADT2.h"


struct stack_type {
        Item *contents;         // <- creating a pointer
        int top;                //not necessary to change from "int" to "Item" since it's just a counter
        int size;               //Instead of #define STACK SIZE 100, we use this
        int length;
        };



static void terminate(const char *message)
{
    printf("%s\n",message);
    exit(EXIT_FAILURE);
}
static void double_size(Stack s)
{
    s->size = 2* s->size;
    s->contents = realloc(s->contents, s->size* sizeof(Item));

}
Stack create(int size)  // creates a stack, user inputs the size that it allocates in memory, in other words the number of elements
{
    Stack s= malloc(sizeof(struct stack_type));     //allocating space for the structure
    if(s==NULL)
        terminate("Error in create: stack could not be created.");
    s->contents = malloc (size * sizeof(Item));   //allocating space for our element
    if(s->contents == NULL)
    {
        free(s);
        terminate("Error in create: stack could not be created.");
    }
    s->top=0;           //initializes
    s->size=size;       //stores the size in the structure as a variable
    s->length=0;
    return s;
}

void destroy(Stack s)
{
    free(s->contents);
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
    return s->top == s->size;
}

void push(Stack s, Item i)
{

    if(is_full(s))
    {
        printf("Stack is full. Allocating double\n");
        double_size(s);
    }

    s->length++;
    s->contents[s->top++]=i;    //accesess the 'top' element from the structure


}

Item pop(Stack s)
{
    if(is_empty(s))
        terminate("Error in pop: stack is empty.");
    s->length--;
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

Item length(Stack s)
{
    return s->length;
}

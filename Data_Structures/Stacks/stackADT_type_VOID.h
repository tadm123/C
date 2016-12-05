#ifndef STACKADT_TYPE_VOID_H
#define STACKADT_TYPE_VOID_H

#include <stdbool.h>
#include <string.h>

typedef struct stack_type *Stack;  //Stack is now a pointer to the structure 'stack_type'

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, void *p);
void *pop(Stack s);

int length(Stack s);
void print(Stack s);        //my own function, it prints the values in the stack

void *peek(Stack s);
#endif // STACKADT_TYPE_VOID_H

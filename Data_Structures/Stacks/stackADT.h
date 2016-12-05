#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>

typedef int Item;           //you can chainge the data type to anything

typedef struct stack_type *Stack;  //Stack is now a pointer to the structure 'stack_type'

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);
void print(Stack s);        //my own function, it prints the values in the stack

Item peek(Stack s);
#endif // STACKADT_H

//Making structures as pointers it's better than as Structures, because
//instead of making a copy of it, it actually calls the original structure

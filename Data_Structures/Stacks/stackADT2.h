#ifndef STACKADT2_H_INCLUDED
#define STACKADT2_H_INCLUDED

#include <stdbool.h>

typedef int Item;           //you can chainge the data type to anything

typedef struct stack_type *Stack;  //Stack is now a pointer to the structure 'stack_type'

Stack create(int size);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);
void print(Stack s);
Item length(Stack s);
Item peek(Stack s);
#endif // STACKADT2_H_INCLUDED

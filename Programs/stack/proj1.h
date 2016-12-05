#ifndef PROJ1_H
#define PROJ1_H

#include <stdbool.h>

typedef char Item;
typedef struct stack_type *Stack;

void stack_overflow(void);
void stack_underflow(void);

void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
Item pop(Stack s);
void push(Stack s,char i);\
Stack create(void);
void destroy(Stack s);
void process_character(Stack s,char ch);

#endif // PROJ1_H

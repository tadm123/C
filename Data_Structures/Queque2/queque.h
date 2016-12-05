#ifndef QUEQUE_H
#define QUEQUE_H

#include <stdbool.h>

typedef int Item;

typedef struct queque_type *Queque;

Queque create();
void destroy(Queque q);

void insert_item(Queque q,Item i);
void remove_item(Queque q);
Item get_first(Queque q);
Item get_last(Queque q);

bool is_full(Queque q);
bool is_empty(Queque q);
void print(Queque q);

void make_empty();
#endif // QUEQUE_H

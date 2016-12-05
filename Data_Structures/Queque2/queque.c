

#include <stdio.h>
#include <stdlib.h>
#include "queque.h"

#define SIZE 50

struct queque_type{
        Item contents[SIZE];
        int top;
        };

static void terminate(const char *message)
{
    printf("%s\n",message);
    exit(EXIT_FAILURE);
}

Queque create(void)  //allocates memory for a stack
{
    Queque q= malloc(sizeof(struct queque_type));     //allocating space for the structure
    if(q==NULL)
        terminate("Error in create: queque could not be created.");
    q->top=0;       //initializes stack to an 'empty' state (ex: top=0, no elements... top=1, it has now 1 element)
    return q;
}

void destroy(Queque q)
{
    free(q);
}



void insert_item(Queque q,Item i)
{
    if(is_full(q))
        terminate("Queque is full already.");

    q->contents[q->top++]=i;

}

void remove_item(Queque q)  //ex top= 2
{
    int n;

    if (is_empty(q))
        terminate("Queque is empty");


    for(n=0;n< q->top;n++)                //contents[0]= contents[1];
        q->contents[n]=q->contents[n+1];    //contents[1]= contents[2];
                                      //contents[2]= contents[3];
    q->top--;

}

Item get_first(Queque q)
{
    return q->contents[0];
}

Item get_last(Queque q)
{
    return q->contents[q->top-1];
}

void make_empty(Queque q)
{
    q->top=0;
}

bool is_empty(Queque q)
{
    return q->top == 0;
}

bool is_full(Queque q)
{
    return q->top == SIZE;
}

void print(Queque q)
{
    int i;

    printf("Elements of queque are:\n");

    for(i=(q->top)-1;i>=0;i--)
        printf("%d\n",q->contents[i]);
}

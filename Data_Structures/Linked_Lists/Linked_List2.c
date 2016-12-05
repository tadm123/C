/* This program inserts a node into the linked list */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int values;
    struct node *next;
    };

struct node *first=NULL;        //first is head

struct node *add_to_list(struct node *list, int n);
void print(struct node *list);

int main()

    struct node *new_node;
    new_node=first;

    struct node *p;


    first=add_to_list(first,10);
    first=add_to_list(first,30);
    first=add_to_list(first,400);
    first=add_to_list(first,1);
    first=add_to_list(first,50);
    first=add_to_list(first,96);


    new_node= malloc(sizeof(struct node));


    for(p=first;p!=NULL;p=p->next)
        printf("%d ",p->values);

    return 0;
}

//function inserts a node into the linked list
struct node *add_to_list(struct node *list, int n)
{
    struct node *new_node=NULL;

    new_node= malloc(sizeof(struct node));
    if (new_node== NULL)
    {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->values=n;
    new_node->next=list;
    return new_node;
}

void print(struct node *list)
{
    struct node *p;     //temp

    for( p= list;p !=NULL; p=p->next)
        printf("%d ",p->values);

}
struct node *read_numbers(void)
{
    struct node *first=NULL;
    int n;

    printf("Enter a series of integers (0 to terminate): ");
    for (;;)
    {
        scanf("%d",&n);
        if(n==0)
           return first;
        first=add_to_list(first,n);
    }
}

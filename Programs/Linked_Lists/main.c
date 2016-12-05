#include <stdio.h>
#include <stdlib.h>

struct node{
    int values;
    struct node *next;
    };

struct node *first=NULL;        //first is head

struct node *add_to_list(struct node *list, int n);
struct node *read_numbers(void);
void print(struct node *list);
struct node *delete_from_list(struct node *list, int n);
void erase(void);

int main()
{
    /*
    struct node *new_node;
    new_node=first;
    */

    first= read_numbers();

    print(first);

    printf("\n");

    //'first= delete_from_list(first,100);

    printf("Type the number you want to delete: ");
    erase();

    print(first);

    /*
    struct node *p;


    new_node= malloc(sizeof(struct node));


    for(p=first;p!=NULL;p=p->next)
        printf("%d ",p->values);  */

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


struct node *delete_from_list(struct node *list, int n)
{
    struct node *cur,*prev;

    for (cur= list, prev=NULL;
         cur != NULL && cur->values != n;
         prev = cur, cur = cur->next)
     ;

    if(cur ==NULL)
        return list;
    if(prev == NULL)
        list=list->next;
    else
        prev->next = cur->next;
    free(cur);
    return list;
}

void erase(void)
{
    int number;
    struct node **pp;
    pp= &first;

    struct node *temp;


    scanf("%d",&number);
    while(*pp)
    {
        if((*pp)->values == number)
        {
            temp=*pp;
            *pp=(*pp)->next;
            free(temp);
            return;
        }
        pp=&(*pp)-> next;
    }
}

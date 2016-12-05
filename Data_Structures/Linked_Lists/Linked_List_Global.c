/*Linked list, inserting node at the beggining of the list
  Important that struct node *head is declared as global
  variable in here*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    };

struct node *head=NULL;    // There's nothing initially (our head points to NULL, it's a NULL pointer)
                           // our head pointer will point always at the beggining of the list
                           //  head->[5|* ]-> [60 | * ]-> [ 4 |NULL]

void insert(int n);
void print();

int main(void)
{
    int n,i,x;
    printf("How many numbers?\n");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        printf("Enter the number\n");
        scanf("%d",&x);
        insert(x);
        print();
    }

    return 0;
}

void insert(int n)
{
    struct node *temp = malloc(sizeof(struct node));  //creating our node
    temp->data= n;          //filling in the data in node
    temp->next= head;       //our 'next' pointer inside our node structure, points to head pointer
                            //which was NULL originally

    head = temp;  //head now points to the node that we just created (the beggining of the list)
}

void print()
{
    struct node *temp = head;  //this temp node now has the address of the head now

    printf("List is: ");
    while(temp != NULL)
    {
        printf(" %d", temp->data);
        temp=temp->next;        //when temp reaches NULL (which is a marker) we'll exit the loop
    }

    printf("\n");
}



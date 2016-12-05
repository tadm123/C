/* Now using double pointers and passing the address of the
   original head pointer to directly modify it, it's similary
   to the Linked_list1 where we had declare head as global(external) variable*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    };


void insert(struct node **pointerToHead, int n);    //it's void now, not returning any structure pointer
void print(struct node *head);

int main(void)
{
    struct node *head=NULL;
    int n,i,x;
    printf("How many numbers?\n");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        printf("Enter the number\n");
        scanf("%d",&x);
        insert(&head,x);    //we're literally passing the original head pointer (its address)
                            //so it works much like like Linked_list1, where we modify it directly
        print(head);
    }

    return 0;
}

void insert(struct node **pointerToHead, int n)   //to avoid confusion let's name this pointerToHead
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data= n;
    temp->next= *pointerToHead;

                                            //**pointerToHead= &head
                                            // so "*pointerToHead" is an alias for the pointer "head"
    *pointerToHead = temp;

}


void print(struct node *head)   //this head is a copy so it won't alter anything
{
    printf("List is: ");
    while(head != NULL)
    {
        printf(" %d", head->data);
        head=head->next;
    }

    printf("\n");
}



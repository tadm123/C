/* Linked Lists Optional Input */

#include <stdio.h>
#include <stdlib.h>


struct node{

    int data;
    struct node *next;
    };

struct node *head;  //head pointers holds the address of the starting node of the linked list

int createLinkedList()
{
    struct node *newnode,*temp;
    newnode= (struct node*)malloc(sizeof(struct node));  //creation of a newmode
    printf("Enter the data into the linkedlist: ");
    scanf("%d",&newnode->data);
    newcode->next= NULL;

    if(head == NULL)
    {
        head=newnode;
        return 1;
    }
    else
    {
        temp=head;
        while(temp->next != NULL)
            temp = temp->next;
    }
    temp-> next = newnode;
}

void display()
{
    struct node *temp;
    if(head != NULL)
        for(temp =head; temp != NULL; temp->next)
            printf("%d ",temp->data);
    else
        printf("The list is empty");

}

int main()
{
    int ch;
    head= NULL;
    do
    {
        printf("1. Create linkedlist");
        printf("2. Display linkedlist");
        printf("3. Exit");
        printf("Enter our choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: createLinkedList();
                    break;
            case 2: display();
                    break;
            case 3: exit(1);
                    break;
            default: printf("Wrong entry try again...");
                    break;
        }
    }while (ch != 3);
}

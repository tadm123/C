/* Original: Maintains a parts database (array version) */

/*
#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part{
    int number;
    char name[NAME_LEN+1];
    int on_hand;
    }inventory[MAX_PARTS];

int num_parts=0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);


int main(void)
{
    char code;

    for(;;)
    {
        printf("Enter operation code: ");
        scanf(" %c",&code);      //leaving blank at beggining spits all white space of input
        while(getchar() != '\n')   //skips tp the end of line
            ;

        switch(code)
        {
            case 'i': insert();
                      break;
            case 's': search();
                      break;
            case 'u': update();
                      break;
            case 'p': print();
                      break;
            case 'q': return 0;
            default:  printf("Illegal code\n");
        }
        printf("\n");
    }
}

int find_part(int number)
{
    int i;

    for(i=0;i<num_parts ; i++)
        if(inventory[i].number == number)
            return i;
    return -1;
}

void insert(void)
{
    int part_number;

    if(num_parts == MAX_PARTS)
    {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if(find_part(part_number) >= 0)
    {
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;
}

void search(void)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i= find_part(number);
    if (i >= 0)
    {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    }
    else
        printf("Part not found.\n");
}

void update(void)
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i= find_part(number);
    if(i >= 0)
     {
         printf("Enter change in quantity on hand: ");
         scanf("%d", &change);
         inventory[i].on_hand += change;
     }
     else
        printf("Part not found.\n");
}

void print(void)
{
    int i;

    printf("Part Number    Part Name                     "
           "Quantity on Hand\n");
    for(i=0; i< num_parts; i++)
        printf("%7d        %-25s%11d\n", inventory[i].number,
               inventory[i].name, inventory[i].on_hand);
}
*/
/* Using a Linked List */


#include <stdio.h>
#include <stdlib.h>
#include "read_line.h"

#define NAME_LEN 25

struct part{
    int number;
    char name[NAME_LEN+1];
    int on_hand;
    struct part *next;
    };

struct part *inventory= NULL;   //points to the starting part

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void erase(void);    //erases part from the database

int main()
{
    char code;

    for(;;)
    {
        printf("Enter operation code: ");
        scanf(" %c",&code);
        while(getchar() != '\n')
            ;

        switch(code)
        {
            case 'i': insert();
                      break;
            case 's': search();
                      break;
            case 'u': update();
                      break;
            case 'p': print();
                      break;
            case 'e': erase();
                      break;
            case 'q': return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");
    }
}
                                        // 1   3   5  8   15
struct part *find_part(int number)      // find = 5
{
    struct part *p;

    for(p=inventory;
        p != NULL && number > p->number;  //8>5
        p= p->next)
        ;
    if(p != NULL && number == p->number)
        return p;
    return NULL;
}

void insert(void)
{
    struct part *cur,*prev, *new_node;

    new_node= malloc(sizeof(struct part));
    if(new_node ==NULL)
    {
        printf("Database is full, can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for(cur = inventory, prev= NULL;
        cur != NULL && new_node->number > cur->number;
        prev = cur, cur=cur->next)
        ;

    if( cur != NULL && new_node->number == cur->number)
    {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next=cur;
    if(prev ==NULL)
        inventory= new_node;
    else
        prev->next= new_node;
}

void search(void)
{
    int number;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p= find_part(number);
    if(p!= NULL)
    {
        printf("Part name: %s\n",p->name);
        printf("Quantity on hand: %d\n",p->on_hand);
    }
    else
        printf("Part not found.\n");
}

void update(void)
{
    int number, change;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p=find_part(number);
    if(p!= NULL)
    {
        printf("Enter change in quantity on hand: ");
        scanf("%d",&change);
        p->on_hand +=change;       //p->on_hand= p->on_hand + change;
    }
    else
        printf("Part not found.\n");
}

void print(void)
{
    struct part *p;
    printf("Part Number   Part Name              "
           "Quantity on Hand\n");
    for(p=inventory; p!= NULL; p=p->next)
        printf("%7d      %-25s%11d\n",p->number,p->name,
                                 p->on_hand);
}

/* Erases a part from the inventory */
void erase(void)
{
    int part_number;
    printf("Enter part number: ");
    scanf("%d", &part_number);

    struct part **pp = &inventory;   //assignging a double pointer to the address of inventory, now *p works the same as 'inventory'
    struct part *temp;
    while (*pp)
     {
        if ((*pp)->number == part_number)  //the same as inventory->number
        {
            temp = *pp;         //temp is the as 'inventory'
            *pp = (*pp)->next;
            free(temp);
            return;             //or continue;
        }
        pp = &(*pp)->next;    // goes to the next one (going through all nodes)
      }
}

/*
struct node *delete_from_list(struct node *list, int n)
{
    struct node *cur,*prev;

    for(cur=list, prev=NULL;
        cur !=NULL && cur->value !=n;
        prev=cur,cur=cur->next)
        ;

        if(cur==NULL)
            return list;
        if(prev==NULL)
            list=list->next;
        else
            prev->next= cur->next;
        free(cur);
        return list;
}
*/
/* Using Dynamic memory Allocation, when the array goes over 10 elements
   it executes realloc to increase to twice the size of it's memory. */
/*
#include <stdio.h>
#include <stdlib.h>
#include "read_line.h"

#define NAME_LEN 25
#define INITIAL_PARTS 10

struct part{
    int number;
    char name[NAME_LEN+1];
    int on_hand;
};

int num_parts =0;
int max_parts= INITIAL_PARTS;
struct part *inventory;

int find_parts (int number);
void insert(void);
void search(void);
void update(void);
void print(void);



int main(void)
{
    char code;

    inventory=malloc( max_parts* sizeof(struct part));
    if(inventory == NULL)
        {
            printf("Cannot allocate initial inventory space\n");
            exit(0);
        }

    for (;;)
    {
        printf("Enter operation code: ");
        scanf(" %c",&code);
        while(getchar() != '\n')
            ;
        switch(code)
        {
            case 'i': insert();
                      break;
            case 's': search();
                      break;
            case 'u': update();
                      break;
            case 'p': print();
                      break;
            case 'q': return 0;
            default:  printf("Illegal code\n");
        }
        printf("\n");
    }
}


int find_part(int number)
{
    int i;

    for (i=0; i<num_parts;i++)
        if(inventory[i].number==number)
            return i;
    return -1;
}

void insert(void)
{
    int part_number;

    if(num_parts == max_parts)
    {
        printf("Array is full, executed realloc to increase space.\n");
        max_parts += INITIAL_PARTS;  //now it's 20
        inventory=realloc(inventory, max_parts*sizeof(struct part));
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if(find_part(part_number) >=0)
    {
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;      //insert part number
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN); //insert name
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);     //insert on_hand

    num_parts++;
}


void search(void)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d",&number);
    i= find_part(number);
    if( i>= 0)
    {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    }
    else
        printf("Part not found.\n");
}

void update(void)
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i= find_part(number);
    if( i>= 0)
    {
        printf("Enter change in quantity on hand: ");
        scanf("%d",&change);
        inventory[i].on_hand += change;

    }
    else
        printf("Part not found.\n");
}

void print(void)
{
    int i;

    printf("Part Number   Part Name       "
           "Quantity on Hand   Price\n");

    for(i=0 ;i< num_parts;i++)

        printf("%7d       %-25s%4d\n",inventory[i].number,
               inventory[i].name, inventory[i].on_hand);
}
*/

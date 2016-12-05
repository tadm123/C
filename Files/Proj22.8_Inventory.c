/* Maintains a parts database (array version)
   includes dump(saves database into a file)
   and restore (loads datatabase from a file) */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part{
    int number;
    char name[NAME_LEN+1];
    int on_hand;
    }inventory[MAX_PARTS],inv1[MAX_PARTS],inv2[MAX_PARTS];

int num_parts=0;

int compare_parts(const void *p, const void *q);
int read_line(char str[], int n);
int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void restore(void);
void dump(void);
void merge(void);

int main(void)
{
    char code;

    printf("i: insert\ns: search\n");
    printf("u: update\np: print\n");
    printf("d: dumps\nr: restores\n\n");

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
            case 'd': dump();
                      break;
            case 'r': restore();
                      break;
            case 'q': return 0;
            default:  printf("Illegal code\n");
        }
        printf("\n");
    }
}
int compare_parts(const void *p, const void *q)
{
    return (*(int*)p-*(int*)q);
}
int read_line(char str[], int n)
{
    int ch, i=0;


    while(isspace(ch=getchar()))
        ;
    while(ch != '\n' && ch != EOF)\
    {
        if(i<n)
            str[i++]=ch;
        ch= getchar();
    }
    str[i]= '\0';
    return i;
}
int find_part(int number)
{
    int i;

    for(i=0;i<num_parts ; i++)
        if(inventory[i].number == number)
            return i;
    return -1;
}

void dump() //want to save inventory array structure into inventory.dat file
{

    char filename[FILENAME_MAX];
    FILE *fp;

    printf("Enter name of output file: ");
    fgets(filename, FILENAME_MAX, stdin);

    if(filename[strlen(filename)-1] == '\n')
        filename[strlen(filename)-1] = '\0';            //puts a '\0' at the end ex: test.txt\0

    if((fp=fopen(filename,"wb")) == NULL)
    {
        fprintf(stderr, "Couldn't create file.\n");
        exit(EXIT_FAILURE);
    }

    fwrite(inventory,sizeof(inventory[0]),num_parts,fp);        //or sizeof(struct part),  just 1 struct part


    fclose(fp);

}

void restore(void)
{
    char filename[FILENAME_MAX];
    FILE *fp;

    printf("Enter name of input file: ");
    fgets(filename, FILENAME_MAX, stdin);

    if(filename[strlen(filename)-1] == '\n')
        filename[strlen(filename)-1] = '\0';            //puts a '\0' at the end ex: test.txt\0


    if((fp=fopen(filename,"rb")) == NULL)
    {
        fprintf(stderr, "Couldn't open file.\n");
        exit(EXIT_FAILURE);
    }
    num_parts=fread(inventory,sizeof(inventory[0]),MAX_PARTS,fp);  //updates the num_parts to be equal to the one in the file , since fread returns the number of elements it will store in num_parts accordingly.
    fclose(fp);
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

    qsort(inventory,num_parts,sizeof(inventory[0]),compare_parts);

    printf("Part Number    Part Name                   "
           "Quantity on Hand\n");
    for(i=0; i< num_parts; i++)
        printf("%7d        %-25s%11d\n", inventory[i].number,
               inventory[i].name, inventory[i].on_hand);
}

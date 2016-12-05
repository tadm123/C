/* Structures size and offsetof() */

#include <stdio.h>
#include <ctype.h>
#include <stddef.h>   //need this for offsetof() function

#define NAME_LEN 25
#define MAX_PARTS 100

struct part{
    int number;               //size=4
    char name[NAME_LEN+1];    //size=26
    int on_hand;              //size=4
    }s[10];                   //size of structure = 4+26+4= 34

int main()
{

    printf("%d\n",offsetof(struct part,name)); //offset from start (0 to beggining of name[] array
    printf("%d\n",offsetof(struct part,on_hand));

    /*We can see using offsetof that in reality there are 2 holes
     between the end of name[] and the start of on_hand
      array is 4+26+2 = 32
                    ^       */

    printf("Size of the structure: %d\n",sizeof(struct part)); //the size of the structure (essentially just 1 element)

    printf("Size of the variable of array of structures %d\n",sizeof(s)); //the size of the variable structure 's', if it's an array of structures s[10]

    return 0;               //it will obviously multiply each element by the size of the structure (360)
}

/* Using the offsetof( , ) to know spot holes and know the size of a structure */

#include <stdio.h>
#include <stddef.h>     //need this library for "offsetof"

struct s{       //theoretically the sizes should be
    char a;     //size= 1
    int b[2];   //size= 8
    float c;    //size= 4
};
                        //13 bytes
int main()
{

   struct s my_struct;

   printf("Size of structure: %d\n", sizeof(struct s));
   printf("Size of 'a': %d\n",sizeof(my_struct.a));
   printf("Size of 'b': %d\n",sizeof(my_struct.b));
   printf("Size of 'c': %d\n",sizeof(my_struct.c));

   printf("%d\n",offsetof(struct s,b));
   printf("%d\n",offsetof(struct s,c));

   printf("%p",&my_struct.b);
    return 0;
}

//bit in actuality as shown int the output, there's a hole of 3 bytes between the first element (a) and the second (b)
//0060FF00 is location of variable a .. 60ff01,60ff02,60ff03 are holes. 60ff04 is the location of the b variable

//offsetof calculates the offset from the beginning to the start of that variable.
//As we can see on the output the offset from the beginning to the start of b is 4
//Which ins reality should be just 1. So there are 3 holes between the first element and the second.
//the offsetof(struct s, c) calculates the offset from the beginning up until the start of C
//which is 12 (note it didn't add the size of the last because it's the offset of the last.

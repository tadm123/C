/* This program prints the number in decimal, binary,
   octadecimal and hexadecimal forms */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *byte_to_binary_str(int byte)
{
    static char bit_string[9]; //no need to store all 32 bits  (33 including '\0'), you will store just 8
    bit_string[0] = '\0';      //and put it in the loop of function 'print_int_bits()' to iterate 4 times so it will print all values

    int mask;
    for (mask = 1<<7; mask > 0; mask >>= 1)
        /* Check if the mask bit is set */
        strcat(bit_string, byte & mask ? "1" : "0");

    return bit_string;
}

int main()
{

    int i;

    printf("Decimal   Hexa     Octal     Binary\n");
    printf("___________________________________\n");

    for( i=1 ; i<= 1<<7; i= i<<1)
         printf("%4d%9x%9o\t   %s\n",i,i,i,byte_to_binary_str(i));

    return 0;
}

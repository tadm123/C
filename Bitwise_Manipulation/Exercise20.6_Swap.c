/* This program converts bytes to a binary string and also
   contains functions to reverse bits */

#include <stdio.h>
#include <string.h>

#define INT_BITS (sizeof(int) * 8 - 1)

char *byte_to_binary_str(int byte)
{
    static char bit_string[9]; //no need to store all 32 bits  (33 including '\0'), you will store just 8
    bit_string[0] = '\0';      //and put it in the loop of function 'print_int_bits()' to iterate 4 times so it will print all values

    int mask;

 for (mask = 1<<7; mask > 0; mask >>= 1)  //mask = mask >> 1
        /* Check if the mask bit is set */
        strcat(bit_string, byte & mask ? "1" : "0");

    return bit_string;
}

void print_int_bits(int value)
{
    int i;

    printf("Binary\t");

    for (i = sizeof(int) - 1; i >= 0; i--)
        printf("%s ", byte_to_binary_str(value >> (i * 8)));

    printf("\n");
}
/* Own function */
unsigned int reverse_bits(unsigned int i) //11000101 00000000 00000000 11000101
{
    unsigned int last,first;
    int counter=0;
    int a=31, b=0;

    while(counter< (sizeof(i)*8)/2)
    {

        last =  i>>a & 1;      //shifts all bit to the start ( 00000001)
        first = i>>b  & 1;      //shifts all bits to the start (00000001)

        i &= ~(1<<b);       //clears bit 0
        i |= last<<b;          // OR with last bit (copies last bit into bit 0)

        i &= ~(1<<a);      //clears bit 31
        i |= first<<a;         //copies first bIt into bit 31


        a--,b++,counter++;

    }

    return i;

}
/* Function copies the bitfield 'n' into a new bitfield 'm', but it's on reversed */

unsigned int reverse_bits2(unsigned int n)
{
    int i, m = 0;                           //m is our new bitfield in which all bits from 'n' are copied in from right to left
    for (i = INT_BITS; i >= 0; i--)
        if (n & (1 << i))           //if it's 1 (any positive number really to activate the 'if' expression)
            m |= (1 << ((INT_BITS) - i));   //copy 1 into m

    return m;
}

/* Reverse bits in place in O(number of bits / 2)
 * Comapres bits 0..15 to bits 31..16 */

unsigned int reverse_bits3(unsigned int n)
{
    int i;
    for (i = 0; i <= INT_BITS / 2; i++)
        /* Ignore if both bits to be swapped  match */
        if (((n >> INT_BITS - i) & 1) != ((n >> i) & 1))    //if they are opposite (1 and 0) from each end, swap them (very intelligent way)
            n ^= (1 << INT_BITS - i) | (1 << i);


    return n;
}


int main(void)
{

   unsigned int var= 0xC50000C5;  //11000101 00000000 00000000 11000101

    printf("Original:\n");
    print_int_bits(var);

    printf("\n\n");

    printf("Reverse bits1:\n");
    print_int_bits(reverse_bits(var));

    printf("Reverse bits2:\n");
    print_int_bits(reverse_bits2(var));

    printf("Reverse bits3:\n");
    print_int_bits(reverse_bits3(var));


    return 0;
}

/* Program rotates a 32 bit either to the left or the right*/


#include <stdio.h>
#include <string.h>

unsigned int _rotl(const unsigned int value, int shift)
{
    // If all bits in value are zero, do nothing and return
    int bitmaskOfAllOnes = sizeof(value)*8 - 1;
    if ((shift &= bitmaskOfAllOnes) == 0)           //This is an optimizer (for speed)
      return value;                                 //It avoids doing more work when the rotation is 0 or a multiple of the size of value

    // Shift value to the left
    return (value << shift) | (value >> (sizeof(value)*8 - shift));
                                // shifting right to handle the wrap around

}

/*unsigned int rotate_right(unsigned int i, int n)
{
    return (i << (sizeof(int) * 8) - n) | (i >> n);
}*/

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


void print_int_bits(int value)
{
    int i;

    printf("Binary\t");

    for (i = sizeof(int) - 1; i >= 0; i--)
        printf("%s ", byte_to_binary_str(value >> (i * 8)));

    printf("\n");
}

int main(void)
{

   unsigned int var= 0xA0000000;  //unsigned integer is 4 bytes (32 bits)
                                  //10100000 00000000 00000000 00000000

   printf("Original:\n");

   printf("Hex\t%x\n",var);

   print_int_bits(var);

   printf("\n\n");
   printf("Shifted bitfield:\n");

   printf("Hex\t%x\n",_rotl(var,4));        //printing in hex

   print_int_bits(_rotl(var,4));

    printf("\n%d",sizeof(unsigned short int));


    return 0;
}

#include <stdio.h>
#include <string.h>

#define MK_COLOR(r,g,b) ((long) (b) << 16 | (g) << 8 | (r))

#define get_red(color)  ( (color)  & 0xff )
#define get_green(color) ( ((color) >>8) & 0xff)
#define get_blue(color) ( ((color) >>16) & 0xff)

char *byte_to_binary_str(int byte)
{
    static char bit_string[9];
    bit_string[0] = '\0';

    int mask;
    for (mask = 0x80; mask > 0; mask >>= 1) {
        /* Check if the mask bit is set */
        strcat(bit_string, byte & mask ? "1" : "0");
    }
    return bit_string;
}

int main(void)
{
    int red = 25;       //00011001
    int green = 195;    //11000011
    int blue = 98;      //01100010
    int i,var=0;

     //01100010 11000011 00011001


    int long color= MK_COLOR(red,green,blue);

    printf("Color values\nDecimal\n",color);
    printf("Binary: ");

    for(i=2; i>=0; i--)  //shifting 8 spaces to the right for each iteration
      {
          var = (color >> i*8) & 0xff;
          printf("%s ",byte_to_binary_str(var));

      }

    printf("\n");
    printf("\n");


    printf("Red: %s\n",byte_to_binary_str(get_red(color)));
    printf("Green: %s\n",byte_to_binary_str(get_green(color)));
    printf("Blue: %s\n",byte_to_binary_str(get_blue(color)));

return 0;
}

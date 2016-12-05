/* Direction program */

#include <stdio.h>

enum {NORTH, SOUTH, EAST, WEST} direction;

int main()
{
   int x=0, y=0;
   direction = SOUTH;

   switch(direction)
   {
       case EAST: x++;
                  break;
       case WEST: x--;
                  break;
       case NORTH: y--;
                  break;
       case SOUTH: y++;
                  break;
   }
   printf("%d, %d", x,y);
}

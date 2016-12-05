/* Program prints the date in this form: September 13, 2010
   allow the user to  enter date in either 9-13-2010 or 9/13/2010 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *month(int m)
{
    char *months[]={"January","February","March","April","May",
                    "June", "July","August","September","October",
                    "November","December"};
    return months[m-1];
}

int main(int argc, char *argv[])
{

    int m=0,d=0,y=0;

    printf("Type a date (mm-dd-yyyy) or (mm/dd/yyyy): ");

    if(fscanf(stdin,"%d%*[/-]%d%*[/-]%d",&m,&d,&y) != 3)
        {
            fprintf(stderr, "Not properly formatted.");
            exit(EXIT_FAILURE);
        }


    printf("%s %2d, %4d",month(m),d,y);

    return 0;
}

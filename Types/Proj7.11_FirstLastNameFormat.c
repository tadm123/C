#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch, initial;

    printf("Enter a first and last name: ");

    while ((ch = getchar()) == ' '); //Skip initial white space until first char

    initial = ch;       //initial stores first character (which will be used later)

    while ((ch = getchar()) != ' '); //gets all characters until the white space (first part)

    while ((ch = getchar()) != '\n')  //gets the second part until \n
                                    //if its not a blank space ' '
            putchar(ch);            //prints it

    printf(", %c.", initial);

    return 0;
}

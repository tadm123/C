#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch, initial,array[20]={0};
    int i=0,j=0;

    printf("Enter a first and last name: ");

    while ((ch = getchar()) == ' '); //Skip initial white space until first char

    initial = ch;       //initial stores first character (which will be used later)

    while ((ch = getchar()) != ' '); //gets all characters until the white space (first part)

    while ((ch = getchar()) != '\n')
    {
        array[i]=ch;
        i++;
    }

    printf("%s",array);
    printf(", %c.", initial);

    return 0;
}

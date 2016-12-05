#include <stdio.h>

void reverse_name(char *name);

int main()
{
    char a[30];
    printf("Enter a first and last name: ");
    fgets(a,30,stdin);
    strtok(a, "\n");

    reverse_name(a);

    return 0;
}

void reverse_name(char *name)
{
    char *p = name , initial;

    while(*p && *p == ' ')
        p++;

    initial = *p++;

    while(*p && *p++ != ' ');

    while(*p)
        putchar(*p++);

    printf(", %c.", initial);
}

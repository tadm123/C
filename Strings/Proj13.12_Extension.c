/* Get the extension of a file (memo.txt -> .txt) */

#include <stdio.h>
#include <string.h>

void get_extension(const char *file_name, char *extension)
{
    while(*file_name)               //goes up to NULL
        if(*file_name++ == '.')     //when its '.' go past it
            strcpy(extension,file_name); //copies
}

int main()
{
    char a[]= "memo.txt";
    char ext_string[10];

    get_extension(a,ext_string);
    printf("%s", ext_string);

    return 0;
}

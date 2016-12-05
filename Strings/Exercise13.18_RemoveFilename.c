/* Removes /index.html from an URL */

#include <stdio.h>

void remove_filename(char *url)
{
    while(*url)
        url++;
    while(*url != '/')
        url--;
    *url = '\0';
}


int main()
{
    char array[] = "http://www.knking.com/index.html";
    remove_filename(array);
    printf("%s", array);

    return 0;
}

/* Adds /index.html to an URL */

#include <stdio.h>
#include <string.h>

void build_index_url(const char *domain, char *index_url)
{
    strcpy(index_url, "http://www.");
    strcat(index_url, domain);

    while(*index_url)
        index_url++;

    strcat(index_url, "/index.html");
}

int main()
{
    char address[] = "knking.com";
    char indexed_address[30];

    build_index_url(address, indexed_address);
    printf("%s", indexed_address);

    return 0;
}

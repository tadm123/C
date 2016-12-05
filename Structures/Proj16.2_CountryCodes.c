#include <stdio.h>
#include <stdbool.h>

struct dialing_code{
        char *country;
        int code;
        };

const struct dialing_code country_codes[]=
{
    {"Argentina", 33},
    {"Brasil", 50},
    {"Peru", 15},
    {"Iran", 81},
    {"India", 3},
    {"United States", 1},
    {"Germany", 40}};

int main()
{
    int i = 0, code = 0;

    printf("Enter code: ");
    scanf("%d", &code);

    for(i=0;i < sizeof(country_codes)/sizeof(country_codes[0]);i++)
          if(country_codes[i].code == code)
          {
                printf("%s", country_codes[i].country);
                return 0;
          }
    printf("Error : Invalid Country Code.");

    /* In a continuous loop */
    /*
    bool found = false;
    for(;;)
    {
        printf("Enter a code: ");
        scanf("%d", &code);
        found = false;

        for(i=0;i < sizeof(country_codes)/sizeof(country_codes[0]);i++)
            if(country_codes[i].code == code)
            {
                printf("%s\n", country_codes[i].country);
                found = true;
            }
        if (!found)
            printf("Invalid Code.\n");
    }
    */
    return 0;
}

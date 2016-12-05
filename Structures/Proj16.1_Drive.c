#include <stdio.h>

struct part{
        int number;
        char name[11];
        int on_hand;
        };

int main()
{
    int i;

    struct part part1 = {528, "Disk Drive", 10};

    struct part part2[]= { {528, "Disk Drive", 10},
                           {100, "Boot", 3},
                           {423, "Computer", 5}};

    printf("%d %s %d\n", part1.number, part1.name, part1.on_hand);

    for(i=0; i<3 ; i++)
            printf("%d %s %d\n", part2[i].number,part2[i].name,
                                            part2[i].on_hand);

    return 0;
}

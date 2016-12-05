#include <stdio.h>

int main()
{
    int num=0;
    int tens=0;
    char grade;

    printf("Enter numerical grade: ");
    scanf("%d",&num);

    tens=num/10;

    switch(tens)
    {
        case(0):case(1):case(2):case(3):case(4):case(5):
            grade='F';
            break;
        case(6): grade='D';
                break;
        case(7): grade ='C';
                break;
        case(8): grade = 'B';
                break;
        case(9): grade = 'A';
                break;
        default: printf("Invalid grade.");
                return 0;
    }
    printf("Letter grade: %c",grade);

    return 0;
}

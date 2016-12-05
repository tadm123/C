#include <ctype.h>
#include <stdio.h>

int main(void)
{
  char ch;
  int sum=0;

  printf("Enter a word: ");

  while ((ch = getchar()) != '\n')
      switch (tolower(ch))
    {
        case 'a':case 'e':case 'i':case 'o':case 'u':
            sum += 1;
            break;
        default:
            continue;
    }

    printf("Your sentence contains %d vowels.",sum);

 return 0;
}




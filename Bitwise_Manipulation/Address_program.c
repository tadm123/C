/* Allow the user to view regions of computer memory */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef unsigned char BYTE;     //(1 byte  = 8 bits)

int main(int argc, char *argv[])
{
    unsigned int addr;
    int i,n;
    BYTE *ptr;

    ptr= (BYTE *) fp ;

    printf("Address of main function: %x\n",(unsigned int) main);
    printf("Address of addr function: %x\n",(unsigned int) &addr);

    printf("\nEnter a (hex) address: ");
    scanf("%x",&addr);



    printf("\n");
    printf(" Address            Bytes               Characters\n");
    printf(" -------  ---------------------------  --------------\n");

    ptr = (BYTE *) addr;
    for(; n>0; n -= 10)
    {
        printf("%2X  ", (unsigned int) ptr);
        for(i=0; i<10 && i<n; i++)
            printf("%.2X ", *(ptr +i));     //the address

        for(; i< 10 ; i++)
            printf("   ");
        printf(" ");

        for(i=0 ; i<10 && i<n ; i++)     //loop to print the characters
        {
            BYTE ch= *(ptr + i);
            if(!isprint(ch))            //isprint() checks if the passed character is printable (if its not an ASCII character)
                ch= '.';
            printf("%c", ch);
        }
        printf("\n");
        ptr += 10;
    }
    return 0;
}

/* Displays the contents of a file as bytes and characters */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int i, n, offset;
  unsigned char buffer[10];   //it's the array that will store each line that is read from the file

  if (argc != 2) {
    fprintf(stderr, "usage: viewfile file\n");
    exit(EXIT_FAILURE);
  }

  if ((fp = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  printf("Offset              Bytes              Characters\n");
  printf("------  -----------------------------  ----------\n");

  for (offset = 0; ; offset += 10)
  {
    n = fread(buffer, 1, 10, fp);   //fread(array address, size of each element, number of elements to read, fp)
    if (n == 0)                     //fread returns the number of elements(not bytes) read.
      break;

    printf("%6d  ", offset);

    for (i = 0; i < n; i++)
      printf("%.2X ", buffer[i]);   //prints each byte (character) in hexadecimal

    for (; i < 10; i++)
      printf("   ");

    printf(" ");

    for (i = 0; i < n; i++)         //print characters
    {
      if (!isprint(buffer[i]))      //if it can't be printed (it's not a control key)
          buffer[i] = '.';
      printf("%c", buffer[i]);
    }
    printf("\n");
  }

  printf("\n\n");
  printf("Number of bytes: %d",ftell(fp));

  fclose(fp);
  return 0;
}

/* Creating a file typing a name for it and then writing
   contents on it */
/* You can write a text file or even a source (.c) file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part{
    int number;               //size=4
    char name[NAME_LEN+1];    //size=26
    int on_hand;              //size=4
    }inventory[MAX_PARTS];                   //size of structure = 4+26+4= 34

int main()
{

    char filename[FILENAME_MAX];             //will hold our string containing the name.
    char array[]="Contents, hello there";   //FILENAME_MAX is the length of the string that
    int n,ch;                               //will hold he longest file name that the implementation guratneed can be opened. The longest name you can give a file
    FILE *fp;

    printf("Enter a file name: ");
    fgets(filename, FILENAME_MAX, stdin);

    if(filename[strlen(filename)-1] == '\n')
        filename[strlen(filename)-1] = '\0';            //puts a '\0' at the end ex: test.txt\0

    if((fp=fopen(filename,"wb+")) == NULL)
    {
        fprintf(stderr, "Couldn't create file.\n");
        exit(EXIT_FAILURE);
    }

    //fwrite(array,sizeof(array[0]),strlen(array),fp);

    printf("Write the contents (type 0 to stop): \n");
    while(((ch=getchar()) != EOF) && (ch != '0'))
        putc(ch,fp);


    printf("\n");

    rewind(fp);

    printf("A preview of the contents of file %s:\n",filename);
    printf("\n");
    while((ch=getc(fp)) != EOF)
        putc(ch,stdout);

    fclose(fp);

    return 0;               //it will obviously multiply each element by the size of the structure (360)
}

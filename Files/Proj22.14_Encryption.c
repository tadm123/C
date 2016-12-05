/* This program prompts the user to enter the name of
   a file containing the message to be encrypted.
   The program writes the encrypted file with the same name
   but an added extension of .enc */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

   char filename[FILENAME_MAX];
   int ch,shift, i;
   FILE *fp,*fpout;

   printf("Enter name of file to be encrypted: ");
   fgets(filename,FILENAME_MAX,stdin);

   if(filename[strlen(filename)-1] == '\n') // -1 because array subscripts are less than 1 of the length
      filename[strlen(filename)-1] = '\0';  // char a[3]="hi\0" ,a[0]='h',a[1]='i', a[2]='\0'


   if((fp=fopen(filename,"rb")) == NULL)
   {
       fprintf(stderr,"Couldn't open the file.\n");
       exit(EXIT_FAILURE);
   }

   strncat(filename,".enc",5);

   if((fpout=fopen(filename,"wb")) == NULL)
   {
       fprintf(stderr,"Couldn't create the file.\n");
       exit(EXIT_FAILURE);
   }

   printf("Enter shift amount (1-25): ");
   scanf("%d",&shift);

   printf("Encrypted message: ");


    while((ch=getc(fp)) != EOF)
    {
        if((ch<= 'z') && (ch >= 'a'))
            fprintf(fpout,"%c",((ch-'a')+shift) % 26 + 'a');
        else if((ch<= 'Z') && (ch >= 'A'))
            fprintf(fpout,"%c",((ch-'A')+shift) % 26 + 'A');
        else
            fprintf(fpout,"%c",ch);

    }
    fclose(fp);
    fclose(fpout);
    return 0;
}

/* note that you can't use sscanf(message <- ,..) because
it will always print the first character, you use a pointer
to go through each character.
Note that you CAN do this with fscanf in a file though, but not sscanf
in a string, they are not completely similar

Because when reading from file, it has a pointer
to the place you are reading/writing (don't remember it's name it)
and it increments that pointer after you are reading. for string
it doesn't have that pointer you should manage it your self */

/* Similar code but simple, just to explain sscanf, doesnt have wrap around option and etc

   char ch,message[50]={0};
   int shift,i;
   char *p=message;  //creating our pointer

   printf("Enter shift amount (1-25): ");
   scanf("%d",&shift);

   printf("Encrypted message: ");


   while((sscanf(p++,"%c",&ch) == 1) && (ch != '\0'))
   {
       if(
       ch += shift;
       putchar(ch);

   }
   */

/* This program compresses and uncompresses a file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned char BYTE; //1 byte ( 8 bits -> 0-255 values)

void compress_file(char *filename);
void uncompress_file(char *filename);
bool is_compressed_file(char *filename);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: programname inputfile.\n");
        exit(EXIT_FAILURE);
    }

    if (is_compressed_file(argv[1])) {
        uncompress_file(argv[1]);
    }
    else {
        compress_file(argv[1]);
    }
}

bool is_compressed_file(char *filename)     //"test.txt"
{
    char compression_ext[] = ".rle";
    char *p = filename;

    while (*p++);   //go to the end (*p != '\0')

    while (p >= filename && *p != '.') //goes back.
        p--;

    return strcmp(p, compression_ext) == 0;
}

void compress_file(char *filename)   //filename= "test.txt"
{

    FILE *fpin;
    FILE *fpout;

    if ((fpin = fopen(filename, "rb")) == NULL) {
        printf("Error, cannot open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    char *outfilename = malloc(strlen(filename) + 5); //.rle\0

    strcpy(outfilename, filename);
    strcat(outfilename, ".rle");       //outfilename => This is our FILE* variable that points to the new file

    if ((fpout = fopen(outfilename, "wb")) == NULL) {
        printf("Error, cannot create file %s.\n", outfilename);
        exit(EXIT_FAILURE);
    }
    free(outfilename);

    BYTE origbyte;
    BYTE cmpbyte;
    int pos;            //keep track of the position in the file that we are reading
    BYTE sequence; //Allows sequences up to 255.  This will store the count of each byte

    while (fread(&origbyte, sizeof(BYTE), 1, fpin) > 0) //reads a single element (char unsigned) of the file and stores it in origbyte
    {
        sequence = 1;   //it starts with 1 because when you originally type the character it's 1
        pos = ftell(fpin);  //returns the current file position, after you typed the first character the file position goes from 0L to 1L. So pos = 1

       printf("num bytes in fpun: %d",pos);
        while (fread(&cmpbyte, sizeof(BYTE), 1, fpin) > 0       //reads element of fpin and stores in cmpbyte. Note this is the value 0 not the character '0' (48)
                && cmpbyte == origbyte) //if it's the same, increase sequence
            ++sequence;

        fwrite(&sequence, sizeof(BYTE), 1, fpout);      //writes the count
        fwrite(&origbyte, sizeof(BYTE), 1, fpout);      //writes the byte
        fseek(fpin, pos + (sequence - 1), SEEK_SET);
    }
    fclose(fpin);
    fclose(fpout);
}

void uncompress_file(char *filename)
{
    FILE *fpin;
    FILE *fpout;

    if ((fpin = fopen(filename, "rb")) == NULL) {
        printf("Error, cannot open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    char *outfilename = malloc(strlen(filename) - 3);
    strncpy(outfilename, filename, strlen(filename) - 4);

    if ((fpout = fopen(outfilename, "wb")) == NULL) {
        printf("Error, cannot create file %s.\n", outfilename);
        exit(EXIT_FAILURE);
    }
    free(outfilename);

    BYTE b;
    BYTE repetitions;
    int i = 0,j=0;
    while (fread(&b, sizeof(BYTE), 1, fpin) > 0) {
        if (i % 2 == 0) {
            repetitions = b;
        }
        else {
            for (j = 0; j < repetitions; ++j) {
                fwrite(&b, sizeof(BYTE), 1, fpout);
            }
        }
        ++i;
    }
    fclose(fpin);
    fclose(fpout);
}

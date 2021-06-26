#include "file_handler.h"

unsigned short checkFileExists()
{
    return !0;
}

unsigned short getFileLines()
{
    FILE *fp;
    unsigned short lines = 0;
    char file_char;

    fp = fopen(DATA_FILE, "r");
    file_char = getc(fp);

    while (file_char != EOF) {
        if (file_char == '\n') {
            lines++;
        }
        file_char = getc(fp);
    }

    fclose(fp);
    return lines;
}

void readFile(char existing_items[512][255])
{
    unsigned short file_lines = getFileLines();

    FILE *fp = NULL; 

    fp = fopen(DATA_FILE, "r");

    for (unsigned short i = 0; i < file_lines; i++) {
        fgets(existing_items[i], 255, fp);
    }

    fflush(stdin);
}

void createFile()
{
    FILE *fp;
    printf("Creating file lmao \n");
    fp = fopen(DATA_FILE, "w");
    fclose(fp);
}

void addToFile(char details[])
{
    FILE *fp;
    fp = fopen(DATA_FILE, "a");
    fprintf(fp, "%s", details);
    fclose(fp);
}

void writeToFile(char details[])
{
    FILE *fp;
    fp = fopen(DATA_FILE, "w");
    fprintf(fp, "%s", details);
    fclose(fp);
}

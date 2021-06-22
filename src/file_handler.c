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

char** readFile()
{
    FILE *fp;
    unsigned short file_lines = getFileLines();
    char ** file_contents = malloc(file_lines * sizeof(char*));

    fp = fopen(DATA_FILE, "r");

    for (unsigned short i = 0; i < file_lines; i++) {
        char temp[255];
        fscanf(fp, "%s", &temp);
        printf("%s \n", temp);
    }

    fclose(fp);

    return file_contents;
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
    printf("%s", details);
    FILE *fp;
    fp = fopen(DATA_FILE, "a");
    fprintf(fp, "%s", details);
    fclose(fp);
}

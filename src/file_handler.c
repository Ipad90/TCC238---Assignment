#include "file_handler.h"

#define DATA_FILE "data/data.dat"

char* readFile()
{
    FILE *file;
    char buff[255];

    file = fopen(DATA_FILE, "r+");
    fscanf(file, "%s", buff);
    printf("%s\n", buff);

    fclose(file);

    return "pepega";
}

unsigned short checkFileExists()
{
    return !0;
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
    fp = fopen(DATA_FILE, "w");
    fprintf(fp, "%s", details);
    fclose(fp);
}

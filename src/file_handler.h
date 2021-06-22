#include <stdio.h>
#include <stdlib.h>

#define DATA_FILE "data/data.dat"

unsigned short checkFileExists();

unsigned short getFileLines();

char** readFile();

void createFile();

void addToFile(char value[]);

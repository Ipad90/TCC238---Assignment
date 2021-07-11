#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_FILE "data/data.csv"

unsigned short checkFileExists();

unsigned short getFileLines(void);

void readFile(char existing_items[512][512]);

void createFile(void);

void addToFile(char value[]);

void writeToFile(char details[]);

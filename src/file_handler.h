#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_FILE "data/data.csv"
#define LSIZ 128 
#define RSIZ 10 

unsigned short checkFileExists();

unsigned short getFileLines();

void readFile(char existing_items[512][255]);

void createFile();

void addToFile(char value[]);

void writeToFile(char details[]);

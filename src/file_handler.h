#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned short checkFileExistence(char file_name[]);

unsigned short getFileLines(char file_name[]);

void readFile(char file_name[], char existing_items[512][512]);

void createFile(char file_name[]);

void addToFile(char file_name[], char value[]);

void writeToFile(char file_name[], char details[]);

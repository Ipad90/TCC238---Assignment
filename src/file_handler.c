#include "file_handler.h"

/**
 *  Parameters
 *      None.
 * 
 *  What this does
 *      Checks if the data file exists.
 * 
 *  Return values
 *      1 if the file exists, 0 if it does not.
 */
unsigned short checkFileExistence(char file_name[])
{
    FILE *fp;

    if (fp = fopen(file_name, "r")) {
        fclose(fp);
        return 1;
    }

    return 0;
}

/**
 *  Parameters
 *      None.
 * 
 *  What this does
 *      Gets the amount of lines in the data file.
 * 
 *  Return values
 *      Amount of lines in the data file.
 */
unsigned short getFileLines(char file_name[])
{
    FILE *fp;
    unsigned short lines = 0;
    char file_char;

    fp = fopen(file_name, "r");
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

/**
 *  Parameters
 *      Empty array of strings to contain the contents of the data file.
 * 
 *  What this does
 *      Reads from the data file and stores the contents of the data file
 *      in an array of strings.
 * 
 *  Return values
 *      None.
 */
void readFile(char file_name[], char existing_items[512][512])
{
    unsigned short file_lines = getFileLines(file_name);

    FILE *fp; 

    fp = fopen(file_name, "r");

    for (unsigned short i = 0; i < file_lines; i++) {
        fgets(existing_items[i], 512, fp);
    }

    fflush(stdin);
}

/**
 *  Parameters
 *      None.
 * 
 *  What this does
 *      Creates the data file.
 * 
 *  Return values
 *      None.
 */
void createFile(char file_name[])
{
    FILE *fp;
    fp = fopen(file_name, "w");
    fclose(fp);
}

/**
 *  Parameters
 *      String of characters to be appended in the data file.
 * 
 *  What this does
 *      Appends a line in the data file.
 * 
 *  Return values
 *      None.
 */
void addToFile(char file_name[], char details[])
{
    FILE *fp;
    fp = fopen(file_name, "a");
    fprintf(fp, "%s", details);
    fclose(fp);
}

/**
 *  Parameters
 *      String of characters to be written in the data file.
 * 
 *  What this does
 *      Writes a line in the data file.
 * 
 *  Return values
 *      None.
 */
void writeToFile(char file_name[], char details[])
{
    FILE *fp;
    fp = fopen(file_name, "w");
    fprintf(fp, "%s", details);
    fclose(fp);
}

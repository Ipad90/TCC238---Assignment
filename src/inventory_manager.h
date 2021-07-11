#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DISPLAY_LENGTH 40

struct ItemDetails;

unsigned short getAmountOfItems(void);

struct ItemDetails *searchItem(unsigned short amount_of_items, char item_name[]);

void viewItem(char input[]);

void printHeaderOrFooter(void);

void displayIndividualItem(struct ItemDetails item_to_display, unsigned short print_header, unsigned short print_footer);

void addItem(void);

void updateItem(void);

void deleteItem(char action[]);

void saveSession(unsigned short to_output);

void loadFromLast(void);

void reOrderAfterDelete(unsigned short amount_of_items, unsigned short start_position);

unsigned short checkIfKeywordReserved(char output_text[], char keyword[]);

unsigned short checkIfItemNameExists(char output_text[], char name[]);

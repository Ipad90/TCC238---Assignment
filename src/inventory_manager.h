#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DISPLAY_LENGTH 30

struct ItemDetails;

void searchItem(unsigned short amount_of_items, char item_name[]);

void viewItem(char action[]);

void displayIndividualItem(struct ItemDetails item_to_display, unsigned short print_header, unsigned short print_footer);

void addItem();

void updateItem();

void deleteItem(char action[]);

void saveSession();

void loadFromLast();

void test();

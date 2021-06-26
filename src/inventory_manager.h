#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ItemDetails;

void searchItem(unsigned short amount_of_items, char item_name[]);

void viewItem(char action[]);

void addItem();

void updateItem();

void deleteItem(char action[]);

void saveSession();

void loadFromLast();

void test();

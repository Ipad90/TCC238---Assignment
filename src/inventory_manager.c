#include "inventory_manager.h"
#include "file_handler.h"

struct Item {
    char item_name[255];
    unsigned int item_quantity;
};

void searchItem(char item_name[])
{
    printf("Searching for item: %s \n", item_name);
}

void viewItem()
{
    readFile();
}

void addItem()
{
    unsigned short file_exists = checkFileExists();
    if (file_exists) {
        char item_quantity[255];
        char item_name[255];
        char buffer[300];

        printf("Item name \n");
        scanf("%s", &item_name);
        printf("Item quantity \n");
        scanf("%s", &item_quantity);

        strcpy(buffer, item_name);
        strcat(buffer, "|");
        strcat(buffer, item_quantity);
        strcat(buffer, "\n");
        addToFile(buffer);
    } else {
        createFile();
    }
}

void updateItem()
{

}

void removeItem()
{

}

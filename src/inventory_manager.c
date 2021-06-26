#include "inventory_manager.h"
#include "file_handler.h"

typedef struct {
    char item_name[128];
    unsigned int item_quantity;
} ItemDetails;

ItemDetails items[512];

unsigned short getAmountOfitems()
{
    unsigned short index = 0;
    while (strcmp(items[index].item_name, "") != 0) {
        index++;
    }
    return index;
}

void searchItem(unsigned short amount_of_items, char item_name[])
{
    printf("Searching for item: %s \n", item_name);

    for (unsigned short i = 0; i < amount_of_items; i++) {
        if (strcmp(items[i].item_name, item_name) == 0) {
            printf("Item found \n");
            printf("-----\n");
            printf("Name: %s \n", items[i].item_name);
            printf("Quantity: %5hu \n", items[i].item_quantity);
            printf("-----\n");
            return;
        }
    }
    printf("No item found with the name: %s \n", item_name);
}

void viewItem(char action[])
{
    unsigned amount_of_items = getAmountOfitems();
    
    if (amount_of_items > 0) {
        if (strcmp(action, "all") == 0) {
            printf("Amount of items: %5hu \n", amount_of_items);

            for (unsigned short i = 0; i < amount_of_items; i++) {
                unsigned short item_name_length = 0;
                unsigned short item_quantity_length = 0;
                unsigned short placeholder_length = 0;
                unsigned short j = 0;

                item_name_length = strlen(items[i].item_name);
                item_quantity_length = floor(log10(abs(items[i].item_quantity))) + 1;

                printf("|-----------");
                while (j <= item_name_length) {
                    printf("-");
                    j++;
                }
                printf("-|\n");
                
                printf("| Name     | %s |\n", items[i].item_name);
                printf("| Quantity | %hu", items[i].item_quantity);

                placeholder_length = (item_name_length >= item_quantity_length) ? item_name_length : item_quantity_length;
                j = (item_name_length >= item_quantity_length) ? item_quantity_length : item_name_length;
                
                while (j <= placeholder_length) {
                    printf(" ");
                    j++;
                }

                printf("|\n");

                j = 0;
                if (i + 1 == amount_of_items) {
                    printf("|-----------");
                    while (j <= item_name_length) {
                        printf("-");
                        j++;
                    }
                    printf("-|\n");
                }
            }
        } else {
            searchItem(amount_of_items, action);
        }
    } else {
        printf("No items to be viewed. \n");
    }
}

void addItem()
{
    char *p;
    char input[128];
    unsigned short quantity;
    unsigned short item_next_index = getAmountOfitems();
    
    printf("Enter item name: ");
    scanf("%s", &input);
    strcpy(items[item_next_index].item_name, input);
    fflush(stdin);

    printf("Enter item quantity: ");

    while (fgets(input, sizeof(input), stdin)) {
        quantity = strtol(input, &p, 10);
        if (p == input || *p != '\n') {
            printf("Invalid input for quantity entered. \n");
            printf("Enter item quantity: ");
        } else {
            items[item_next_index].item_quantity = quantity;
            break;
        }
    }

    fflush(stdin);

    printf("Item successfully added! \n");
}

void updateItem()
{
    char *p;
    char input[128];
    char name[128];
    unsigned short quantity;

    printf("Enter item name: \n");
    scanf("%s", &name);
    fflush(stdin);

    printf("Updating item: %s \n", name);
    printf("To update item name, enter the new name for the item. \n");
    printf("If not updating item name, press enter without typing anything. \n");
    printf("Enter item new name: ");
    
    fgets(name, 100, stdin);

    if (strcmp(name, "") == 0) {
        printf("Item new name is: %s \n", name);
        strcpy(items[0].item_name, name);
    }

    fflush(stdin);

    printf("To update item quantity, enter the new quantity for the item. \n");
    printf("If not updating item quantity, press enter without typing anything. \n");
    printf("Enter item new quantity: ");

    while (fgets(input, sizeof(input), stdin)) {
        quantity = strtol(input, &p, 10);
        if (p == input || *p != '\n') {
            printf("Invalid input for quantity entered. \n");
            printf("Enter item new quantity: ");
        } else {
            items[0].item_quantity = quantity;
            break;
        }
    }

    fflush(stdin);

    printf("Item successfully updated! \n");
}

void deleteItem(char action[])
{
    unsigned amount_of_items = getAmountOfitems();
    unsigned short shift_down = 0;
    printf("Searching for item: %s \n", action);

    if (strcmp(action, "all") != 0) {
        for (unsigned short i = 0; i < amount_of_items; i++) {
            //  If action matches with item name, clear array element
            //  Then set flag to push elements down to occupy cleared array element
            if (strcmp(items[i].item_name, action) == 0) {
                strcpy(items[i].item_name, "");
                items[i].item_quantity = 0;
                shift_down = 1;
            }
            //  Push elements down to occupy cleared array element
            if (shift_down) {
                items[i] = items[i + 1];
            }
        }
        printf("Item successfully deleted! \n");
    } else {
        for (unsigned short i = 0; i < amount_of_items; i++) {
            strcpy(items[i].item_name, "");
            items[i].item_quantity = 0;
        }
        printf("All items successfully deleted! \n");
    }
}

void saveSession()
{
    unsigned short amount_of_items = getAmountOfitems();
    printf("Saving all (%hu) items from current session, please wait. \n", amount_of_items);
    if (amount_of_items > 0) {
        for (unsigned short i = 0; i < amount_of_items; i++) {
            char temp[255] = "";
            char quantity[8]= "";
            sprintf(quantity, "%hu", items[i].item_quantity);
            strcat(temp, items[i].item_name);
            strcat(temp, ",");
            strcat(temp, quantity);
            strcat(temp, "\n");
            if (i == 0) {
                writeToFile(temp);
            } else {
                addToFile(temp);
            }
        }
    } else {
        writeToFile("");
    }
    printf("All items successfully saved. \n");
}

void loadFromLast()
{
    char existing_items[512][255];
    unsigned short existing_items_amount = getFileLines();

    printf("Retrieving data from preivous session, please wait. \n");
    readFile(existing_items);
    printf("Previous session had: %hu items. \n", existing_items_amount);
    
    for (unsigned short i = 0; i < existing_items_amount; i++) {
        unsigned short j = 0;
        char temp[2][128];
        char *pch = strtok(existing_items[i], ",");

        while (pch != NULL) {
            strcpy(temp[j++], pch);
            pch = strtok(NULL, "");
        }
        strcpy(items[i].item_name, temp[0]);
        items[i].item_quantity = atoi(temp[1]);
    }
}

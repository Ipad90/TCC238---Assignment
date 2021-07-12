#include "inventory_manager.h"
#include "file_handler.h"

typedef struct ItemDetails
{
    char item_name[128];
    unsigned int item_quantity;
    float item_price;
    char item_supplier[128];
} ItemDetails;

ItemDetails items[512];

const char RESERVED_KEYWORDS[2][16] = {"all", "supplier"};

unsigned short getAmountOfItems(void)
{
    unsigned short index = 0;

    while (strcmp(items[index].item_name, "") != 0) {
        index++;
    }

    return index;
}

struct ItemDetails *searchItem(unsigned short amount_of_items, char item_name[])
{
    printf("Searching for item: %s \n", item_name);

    for (unsigned short i = 0; i < amount_of_items; i++) {
        if (strcmp(items[i].item_name, item_name) == 0) {
            printf("Item found! \n");
            return &items[i];
        }
    }

    printf("Item \"%s\" does not exist.\n\n", item_name);

    return NULL;
}

void viewItem(char input[])
{
    unsigned amount_of_items = getAmountOfItems();
    unsigned short print_header = 0;
    unsigned short print_footer = 0;

    if (amount_of_items > 0) {
        if (stricmp(input, "all") == 0) {
            printf("Viewing all items. \n");
            printf("Amount of items: %d \n", amount_of_items);
            printf("Inventory total worth: \n");

            for (unsigned short i = 0; i < amount_of_items; i++) {
                if (i >= 0) {
                    print_header = 1;
                }

                if (i + 1 == amount_of_items) {
                    print_footer = 1;
                }

                displayIndividualItem(items[i], print_header, print_footer);

                print_header = 0;
                print_footer = 0;
            }
        } else if (stricmp(input, "supplier") == 0) {
            unsigned short something_printed = 0;
            char supplier[128];

            fflush(stdin);
            printf("Enter item supplier name: ");
            fgets(supplier,sizeof(supplier), stdin);
            supplier[strcspn(supplier, "\n")] = 0;

            printf("Viewing items supplied from supplier: \"%s\". \n", supplier);

            for (unsigned short i = 0; i < amount_of_items; i++) {
                if (strcmp(supplier, items[i].item_supplier) == 0) {
                    if (i >= 0) {
                        print_header = 1;
                    }

                    if (i + 1 == amount_of_items) {
                        print_footer = 1;
                    }

                    displayIndividualItem(items[i], print_header, 0);

                    print_header = 0;
                }
            }

            if (something_printed) {
                printHeaderOrFooter();
            } else {
                printf("No item from supplier: \"%s\" found. \n", supplier);
            }
        } else {
            ItemDetails *found_item_pointer = searchItem(amount_of_items, input);
            if (found_item_pointer != NULL) {
                displayIndividualItem(*found_item_pointer, 1, 1);
            }
        }
    } else {
        printf("No items to be viewed. \n");
    }
}

void printHeaderOrFooter(void)
{
    unsigned short i = 0;

    printf("|----------|-");

    while (i < DISPLAY_LENGTH) {
        printf("-");
        i++;
    }

    printf("-|\n");
}

void displayIndividualItem(struct ItemDetails item_to_display, unsigned short print_header, unsigned short print_footer)
{
    unsigned short item_name_length = 0;
    unsigned short item_quantity_length = 0;
    unsigned short item_price_length = 0;
    unsigned short item_supplier_length = 0;
    unsigned short item_worth_length = 0;
    unsigned short longest_attribute_length = 0;
    unsigned short j = 0;

    char stringed_float[16];

    sprintf(stringed_float, "%.2f", item_to_display.item_price);
    item_price_length = strlen(stringed_float);

    strcpy(stringed_float, "");
    sprintf(stringed_float, "%.2f", (item_to_display.item_price * item_to_display.item_quantity));
    item_worth_length = strlen(stringed_float);

    item_name_length = strlen(item_to_display.item_name);
    item_quantity_length = floor(log10(abs(item_to_display.item_quantity))) + 1;
    item_supplier_length = strlen(item_to_display.item_supplier);

    longest_attribute_length = (item_name_length >= item_quantity_length) ? item_name_length : item_quantity_length;
    j = (item_name_length >= item_quantity_length) ? item_quantity_length : item_name_length;

    if (print_header) {
        printHeaderOrFooter();
    }

    if (item_name_length > DISPLAY_LENGTH) {
        unsigned short lines = (longest_attribute_length + DISPLAY_LENGTH - 1) / DISPLAY_LENGTH;
        unsigned short index = 0;

        printf("| Name     | ");

        for (unsigned i = 0; i < lines; i++) {
            for (unsigned short k = 0; k < DISPLAY_LENGTH; k++) {
                printf("%c", item_to_display.item_name[index++]);
            }
            printf(" |\n");
            if (i < lines - 1) {
                printf("|          | ");
            }
        }
    } else {
        printf("| Name     | %s", item_to_display.item_name);
        while (item_name_length < DISPLAY_LENGTH) {
            printf(" ");
            item_name_length++;
        }
        printf(" | \n");
    }

    printf("| Quantity | %d", item_to_display.item_quantity);
    while (item_quantity_length < DISPLAY_LENGTH) {
        printf(" ");
        item_quantity_length++;
    }
    printf(" | \n");

    printf("| Price    | %.2f", item_to_display.item_price);
    while (item_price_length < DISPLAY_LENGTH) {
        printf(" ");
        item_price_length++;
    }
    printf(" | \n");

    if (item_supplier_length > DISPLAY_LENGTH) {
        printf("| Supplier | %s | \n", item_to_display. item_supplier);
    } else {
        printf("| Supplier | %s", item_to_display.item_supplier);
        while (item_supplier_length < DISPLAY_LENGTH) {
            printf(" ");
            item_supplier_length++;
        }
        printf(" | \n");
    }

    printHeaderOrFooter();

    printf("| Worth    | %.2f", (item_to_display.item_price * item_to_display.item_quantity));
    while (item_worth_length < DISPLAY_LENGTH) {
        printf(" ");
        item_worth_length++;
    }
    printf(" | \n");

    if (print_footer) {
        printHeaderOrFooter();
    }
}

void addItem(void)
{
    unsigned short item_next_index = getAmountOfItems();
    unsigned short name_not_reserved = 1;
    unsigned short name_not_duplicate = 1;
    char *p;
    char temp[512];
    char input[128];
    unsigned short quantity;
    float price;

    while (name_not_reserved || name_not_duplicate) {
        printf("Enter item name: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, "") != 0) {
            name_not_reserved = checkIfKeywordReserved("Item name is a reserved keyword. \n", input);
            name_not_duplicate = checkIfItemNameExists("An item with that name already exists. \n", input);
        } else {
            printf("Item name cannot be blank. \n");
        }
        fflush(stdin);
    }

    strcpy(items[item_next_index].item_name, input);
    strcpy(temp, items[item_next_index].item_name);
    strcat(temp, ",");

    printf("Enter item quantity: ");

    while (fgets(input, sizeof(input), stdin)) {
        quantity = strtol(input, &p, 10);
        if (p == input || *p != '\n') {
            printf("Invalid input for quantity entered !\n");
            printf("Enter item quantity: ");
        } else {
            items[item_next_index].item_quantity = quantity;
            break;
        }
    }

    sprintf(input, "%hu", items[item_next_index].item_quantity);
    strcat(temp, input);
    strcat(temp, ",");

    fflush(stdin);

    printf("Enter item price: ");
    scanf("%f", &price);
    items[item_next_index].item_price = price;
    sprintf(input, "%g", price);
    strcat(temp, input);
    strcat(temp, ",");

    fflush(stdin);

    name_not_reserved = 1;

    while (name_not_reserved) {
        printf("Enter item supplier: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, "") != 0) {
            name_not_reserved = checkIfKeywordReserved("Item supplier is a reserved keyword. \n", input);
        } else {
            printf("Item supplier cannot be blank. \n");
        }
        fflush(stdin);
    }

    strcpy(items[item_next_index].item_supplier, input);
    strcat(temp, input);
    strcat(temp, "\n");

    addToFile(temp);
    printf("Item \"%s\" successfully added! \n", items[item_next_index].item_name);
}

void updateItem(void)
{
    char *p;
    char input[8];
    char name[128];
    char supplier[128];
    unsigned amount_of_items = getAmountOfItems();
    unsigned short quantity;
    float price;

    if (amount_of_items > 0) {
        printf("Enter item name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;
        fflush(stdin);

        ItemDetails *item_to_update = searchItem(amount_of_items, name);
        if (item_to_update != NULL) {
            unsigned short name_not_reserved = 1;
            unsigned short name_not_duplicate = 1;

            while (name_not_reserved || name_not_duplicate) {
                printf("Enter item new name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;

                if (stricmp(name, item_to_update->item_name) != 0) {
                    if (strcmp(name, "") != 0) {
                        name_not_reserved = checkIfKeywordReserved("Item new name is a reserved keyword. \n", name);
                        name_not_duplicate = checkIfItemNameExists("An item with that name already exists. \n", name);
                    } else {
                        printf("Item new name cannot be blank. \n");
                    }
                } else {
                    break;
                }
                fflush(stdin);
            }

            printf("Enter item new quantity: ");
            while (fgets(input, sizeof(input), stdin)) {
                quantity = strtol(input, &p, 10);
                if (p == input || *p != '\n') {
                    printf("Invalid input for quantity entered. \n");
                    printf("Enter item new quantity: ");
                } else {
                    break;
                }
            }
            fflush(stdin);

            printf("Enter item new price: ");
            while (fgets(input, sizeof(input), stdin)) {
                price = strtod(input, &p);
                if (p == input || *p != '\n') {
                    printf("Invalid input for price entered. \n");
                    printf("Enter item new price: ");
                } else {
                    break;
                }
            }
            fflush(stdin);

            name_not_reserved = 1;

            while (name_not_reserved) {
                printf("Enter item new supplier: ");
                fgets(supplier, sizeof(supplier), stdin);
                supplier[strcspn(supplier, "\n")] = 0;
                
                if (stricmp(supplier, item_to_update->item_supplier) != 0) {
                    if (strcmp(supplier, "") != 0) {
                        name_not_reserved = checkIfKeywordReserved("Item new supplier is a reserved keyword. \n", supplier);
                    } else {
                        printf("Item new supplier cannot be blank. \n");
                    }
                } else {
                    break;
                }
                fflush(stdin);
            }

            printf("Item new details will be: \n");
            printf("Previous name: %s | New name: %s \n", item_to_update->item_name, name);
            printf("Previous quantity: %d | New quantity: %d \n", item_to_update->item_quantity, quantity);
            printf("Previous price: %.2f | New price: %.2f \n", item_to_update->item_price, price);
            printf("Previous supplier: %s | New supplier: %s \n", item_to_update->item_supplier, supplier);

            strcpy(item_to_update->item_name, name);
            item_to_update->item_quantity = quantity;
            item_to_update->item_price = price;
            strcpy(item_to_update->item_supplier, supplier);

            saveSession(0);
        }
    } else {
        printf("No items in the system to update. \n");
    }
}

void deleteItem(char action[])
{
    unsigned short amount_of_items = getAmountOfItems();

    if (amount_of_items > 0) {
        printf("Searching for item: %s \n", action);
        if (stricmp(action, "all") != 0) {
            for (unsigned short i = 0; i < amount_of_items; i++) {
                if (strcmp(items[i].item_name, action) == 0) {
                    strcpy(items[i].item_name, "");
                    items[i].item_quantity = 0;

                    reOrderAfterDelete(amount_of_items, i);
                    saveSession(0);
                    printf("Item successfully deleted !\n");

                    return;
                }
            }
            printf("Item \"%s\" does not exists. \n", action);
        } else {
            for (unsigned short i = 0; i < amount_of_items; i++) {
                strcpy(items[i].item_name, "");
                items[i].item_quantity = 0;
            }
            printf("All items successfully deleted! \n");
        }
    } else {
        printf("No items in the system to delete. \n");
    }
}

void saveSession(unsigned short to_output)
{
    unsigned short amount_of_items = getAmountOfItems();

    if (to_output) {
        printf("Saving all (%hu) items from current session, please wait. \n", amount_of_items);
    }

    if (amount_of_items > 0) {
        for (unsigned short i = 0; i < amount_of_items; i++) {
            char temp[512] = "";
            char quantity[16] = "";
            char price[32] = "";

            sprintf(quantity, "%d", items[i].item_quantity);
            sprintf(price, "%.2f", items[i].item_price);
            strcat(temp, items[i].item_name);
            strcat(temp, ",");
            strcat(temp, quantity);
            strcat(temp, ",");
            strcat(temp, price);
            strcat(temp, ",");
            strcat(temp, items[i].item_supplier);
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

    if (to_output) {
        printf("All items successfully saved. \n");
    }
}

void loadFromLast(void)
{
    char existing_items[512][512];
    unsigned short existing_items_amount = getFileLines();

    printf("Retrieving data from preivous session, please wait. \n");
    readFile(existing_items);

    for (unsigned short i = 0; i < existing_items_amount; i++) {
        unsigned short j = 0;
        char temp[4][128];
        char *token = strtok(existing_items[i], ",\n");

        while (token != NULL) {
            strcpy(temp[j++], token);
            token = strtok(NULL, ",\n");
        }

        strcpy(items[i].item_name, temp[0]);
        items[i].item_quantity = atoi(temp[1]);
        items[i].item_price = atof(temp[2]);
        strcpy(items[i].item_supplier, temp[3]);
    }
}

void reOrderAfterDelete(unsigned short amount_of_items, unsigned short start_position)
{
    while (start_position < amount_of_items) {
        items[start_position] = items[start_position + 1];
        start_position++;
    }
}

unsigned short checkIfKeywordReserved(char output_text[], char keyword[])
{
    unsigned short amount_of_reserved_keywords = sizeof(RESERVED_KEYWORDS) / sizeof(RESERVED_KEYWORDS[0]);
    unsigned short i = 0;

    while (i < amount_of_reserved_keywords) {
        if (stricmp(keyword, RESERVED_KEYWORDS[i++]) == 0) {
            printf("%s", output_text);
            return 1;
        }
    }

    return 0;
}

unsigned short checkIfItemNameExists(char output_text[], char name[])
{
    unsigned short amount_of_items = getAmountOfItems();
    unsigned short i = 0;

    while (i < amount_of_items) {
        if (stricmp(name, items[i++].item_name) == 0) {
            printf("%s", output_text);
            return 1;
        }
    }

    return 0;
}

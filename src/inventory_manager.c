#include "inventory_manager.h"
#include "file_handler.h"
#include "colour_print.h"

typedef struct ItemDetails
{
    char item_name[128];
    unsigned int item_quantity;
} ItemDetails;

ItemDetails items[512];

unsigned short getAmountOfitems()
{
    unsigned short index = 0;
    while (strcmp(items[index].item_name, "") != 0)
    {
        index++;
    }
    return index;
}

void searchItem(unsigned short amount_of_items, char item_name[])
{
    printf("Searching for item: ");
    green("%s\n", item_name);
    for (unsigned short i = 0; i < amount_of_items; i++)
    {
        if (strcmp(items[i].item_name, item_name) == 0)
        {
            printf("Item found \n");
            displayIndividualItem(items[i], 1, 1);
            return;
        }
    }
    red("Item '%s' does not exist.\n\n", item_name);

}

void viewItem(char action[])
{
    unsigned amount_of_items = getAmountOfitems();
    unsigned short print_header = 0;
    unsigned short print_footer = 0;

    if (amount_of_items > 0)
    {
        if (strcmp(action, "all") == 0)
        {
            printf("Amount of items: ");
            yellow("%d\n", amount_of_items);

            for (unsigned short i = 0; i < amount_of_items; i++)
            {
                if (i >= 0)
                {
                    print_header = 1;
                }

                if (i + 1 == amount_of_items)
                {
                    print_footer = 1;
                }

                displayIndividualItem(items[i], print_header, print_footer);

                print_header = 0;
                print_footer = 0;
            }
        }
        else
        {
            searchItem(amount_of_items, action);
        }
    }
    else
    {
        printf("No items to be viewed. \n");
    }
}

void printHeaderOrFooter()
{
    printf("|----------|-");

    unsigned short i = 0;
    while (i < DISPLAY_LENGTH)
    {
        printf("-");
        i++;
    }

    printf("-|\n");
}

void displayIndividualItem(struct ItemDetails item_to_display, unsigned short print_header, unsigned short print_footer)
{
    unsigned short item_name_length = 0;
    unsigned short item_quantity_length = 0;
    unsigned short longest_attribute_length = 0;
    unsigned short j = 0;

    item_name_length = strlen(item_to_display.item_name);
    item_quantity_length = floor(log10(abs(item_to_display.item_quantity))) + 1;

    longest_attribute_length = (item_name_length >= item_quantity_length) ? item_name_length : item_quantity_length;
    j = (item_name_length >= item_quantity_length) ? item_quantity_length : item_name_length;

    if (print_header)
    {
        printHeaderOrFooter();
    }

    if (item_name_length > DISPLAY_LENGTH)
    {
        unsigned short lines = (longest_attribute_length + DISPLAY_LENGTH - 1) / DISPLAY_LENGTH;
        unsigned short index = 0;

        printf("| Name     | ");

        for (unsigned i = 0; i < lines; i++)
        {
            for (unsigned short k = 0; k < DISPLAY_LENGTH; k++)
            {
                printf("%c", item_to_display.item_name[index++]);
            }
            printf(" |\n");
            if (i < lines - 1)
            {
                printf("|          | ");
            }
        }
    }
    else
    {
        printf("| Name     | %s", item_to_display.item_name);
        while (item_name_length < DISPLAY_LENGTH)
        {
            printf(" ");
            item_name_length++;
        }
        printf(" | \n");
    }

    printf("| Quantity | %hu", item_to_display.item_quantity);

    while (item_quantity_length < DISPLAY_LENGTH)
    {
        printf(" ");
        item_quantity_length++;
    }

    printf(" |\n");

    if (print_footer)
    {
        printHeaderOrFooter();
    }
}

void addItem()
{
    char *p;
    char input[128];
    unsigned short quantity;
    unsigned short item_next_index = getAmountOfitems();

    printf("Enter item name: ");
    scanf("%[0-9a-zA-Z ]", &input);
    strcpy(items[item_next_index].item_name, input);
    fflush(stdin);

    printf("Enter item quantity: ");

    while (fgets(input, sizeof(input), stdin))
    {
        quantity = strtol(input, &p, 10);
        if (p == input || *p != '\n')
        {
            system("cls");
            red("Invalid input for quantity entered !\n");
            yellow("Adding item\n");
            printf("Enter item name: %s\n", items[item_next_index].item_name);
            printf("Enter item quantity: ");
        }
        else
        {
            items[item_next_index].item_quantity = quantity;
            break;
        }
    }

    fflush(stdin);
    system("cls");
    green("Item '%s' successfully added ! \n", items[item_next_index].item_name);
}

void updateItem()
{
    char *p;
    char input[128];
    char name[128];
    unsigned amount_of_items = getAmountOfitems();
    unsigned short quantity;

    if (amount_of_items > 0)
    {
        printf("Enter item name: ");
        scanf("%[0-9a-zA-Z ]", &name);
        fflush(stdin);

        for (unsigned short i = 0; i < amount_of_items; i++)
        {
            if (strcmp(name, items[i].item_name) == 0)
            {
                system("cls");
                yellow("Updating Item : ");
                green("%s\n", name);
                printf("To update item name, enter the new name for the item. \n");
                printf("If not updating item name, press enter without typing anything.\n");
                cyan("New name: ");

                fgets(name, 100, stdin);

                if (strcmp(name, "") == 0)
                {
                    printf("Item new name is: %s \n", name);
                    strcpy(items[0].item_name, name);
                }

                fflush(stdin);

                printf("To update item quantity, enter the new quantity for the item. \n");
                printf("If not updating item quantity, press enter without typing anything. \n");
                cyan("New quantity: ");

                while (fgets(input, sizeof(input), stdin))
                {
                    quantity = strtol(input, &p, 10);
                    if (p == input || *p != '\n')
                    {
                        red("Invalid input for quantity entered. \n");
                        cyan("New quantity: ");
                    }
                    else
                    {
                        items[i].item_quantity = quantity;
                        break;
                    }
                }

                fflush(stdin);
                system("cls");
                green("Item successfully updated !\n");
                return;
            }
        }
        system("cls");
        red("Item '%s' does not exists. \n", name);
    }
    else
    {
        red("No items in the system to update.  ");
    }
}

void deleteItem(char action[])
{
    unsigned amount_of_items = getAmountOfitems();
    unsigned short shift_down = 0;

    printf("Searching for item: ");
    green("%s\n", action);

    if (amount_of_items > 0)
    {
        if (strcmp(action, "all") != 0)
        {
            for (unsigned short i = 0; i < amount_of_items; i++)
            {
                //  If action matches with item name, clear array element
                //  Then set flag to push elements down to occupy cleared array element
                if (strcmp(items[i].item_name, action) == 0)
                {
                    strcpy(items[i].item_name, "");
                    items[i].item_quantity = 0;
                    shift_down = 1;
                }
                //  Push elements down to occupy cleared array element
                if (shift_down)
                {
                    items[i] = items[i + 1];
                }
            }
            system("cls");
            green("Item successfully deleted !\n");
        }
        else
        {
            for (unsigned short i = 0; i < amount_of_items; i++)
            {
                strcpy(items[i].item_name, "");
                items[i].item_quantity = 0;
            }
            system("cls");
            green("All items successfully deleted !\n");
        }
    }
    else
    {
        red("No items in the system to delete\n");
    }
}

void saveSession()
{
    unsigned short amount_of_items = getAmountOfitems();
    printf("Saving all (%hu) items from current session, please wait. \n", amount_of_items);
    if (amount_of_items > 0)
    {
        for (unsigned short i = 0; i < amount_of_items; i++)
        {
            char temp[255] = "";
            char quantity[8] = "";
            sprintf(quantity, "%hu", items[i].item_quantity);
            strcat(temp, items[i].item_name);
            strcat(temp, ",");
            strcat(temp, quantity);
            strcat(temp, "\n");
            if (i == 0)
            {
                writeToFile(temp);
            }
            else
            {
                addToFile(temp);
            }
        }
    }
    else
    {
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
    printf("Previous session had: %hu  \n", existing_items_amount);

    for (unsigned short i = 0; i < existing_items_amount; i++)
    {
        unsigned short j = 0;
        char temp[2][128];
        char *pch = strtok(existing_items[i], ",");

        while (pch != NULL)
        {
            strcpy(temp[j++], pch);
            pch = strtok(NULL, "");
        }
        strcpy(items[i].item_name, temp[0]);
        items[i].item_quantity = atoi(temp[1]);
    }
}

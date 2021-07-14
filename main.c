#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src\inventory_manager.h"

int main(void)
{
    char *p;
    unsigned short action;
    unsigned short continue_running = 1;
    char input[128];
    char secondary_input[4];

    checkDataFileExists(DATA_FILE, 0);
    loadFromDataFile(DATA_FILE);
    printf("\n");

    while (continue_running) {
        printf(" ===== Inventory management system ===== \n");
        printf("--------------------------- \n");
        printf("|    List of actions:     | \n");
        printf("--------------------------- \n");
        printf("| 1 | View item           | \n");
        printf("| 2 | Add item            | \n");
        printf("| 3 | Update item         | \n");
        printf("| 4 | Delete item         | \n");
        printf("| 0 | Exit program        | \n");
        printf("--------------------------- \n");
        printf("What action do you want to perform? ");

        while (fgets(input, sizeof(input), stdin)) {
            action = strtol(input, &p, 10);
            if (p == input || *p != '\n') {
                printf("Invalid input for action entered! \n");
            } else {
                fflush(stdin);
                switch (action) {
                    case 0:
                        saveSession(1);
                        printf("Exiting.");
                        continue_running = 0;
                        break;
                    case 1:
                        printf("------------------------ \n");
                        printf("----- Viewing item ----- \n");
                        printf("------------------------ \n");
                        printf("To view all items, type \"all\". \n");
                        printf("To view all items from a particular supplier, type \"supplier\". \n");
                        printf("To view a specific item, type the name of the item. \n");
                        scanf("%[0-9a-zA-Z ]", input);
                        viewItem(input);
                        break;
                    case 2:
                        printf("------------------------ \n");
                        printf("----- Adding item ------ \n");
                        printf("------------------------ \n");
                        addItem();
                        break;
                    case 3:
                        printf("------------------------ \n");
                        printf("----- Updating item ---- \n");
                        printf("------------------------ \n");
                        updateItem();
                        break;
                    case 4:
                        printf("------------------------ \n");
                        printf("----- Deleting item ---- \n");
                        printf("------------------------ \n");
                        printf("To delete all items, type \"all\". \n");
                        printf("To delete a specific item, type the name of the item. \n");
                        printf("Enter item name: ");
                        fgets(input, sizeof(input), stdin);
                        input[strcspn(input, "\n")] = 0;
                        deleteItem(input);
                        break;
                    case 5:
                        printf("Switch data file \n");

                        while (1) {
                            printf("Enter file name with the file format: ");
                            fgets(input, sizeof(input), stdin);
                            input[strcspn(input, "\n")] = 0;

                            if (!checkDataFileExists(input, 0)) {
                                printf("No file found want to create file? \n");

                                fgets(secondary_input, sizeof(secondary_input), stdin);
                                secondary_input[strcspn(secondary_input, "\n")] = 0;

                                if (stricmp(secondary_input, "yes") == 0) {
                                    createDataFile(input);
                                    clearSession();
                                    loadFromDataFile(input);
                                    break;
                                } else if (stricmp(secondary_input, "no") == 0) {
                                    printf("Not creating new data file, using current data. \n");
                                    break;
                                } else {
                                    printf("Invalid input. \n");
                                }
                            } else {
                                printf("Wtf \n");
                                clearSession();
                                loadFromDataFile(input);
                                break;
                            }
                            fflush(stdin);
                        }
                        break;
                    default:
                        printf("No valid action entered. \n");
                        break;
                }
                fflush(stdin);
            }
            break;
        }
        printf("\n");
    }

    return 0;
}

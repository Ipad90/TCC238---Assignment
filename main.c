#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src\inventory_manager.h"

int main(void) {
    char *p;
    unsigned short action;
    unsigned short continue_running = 0;
    char input[128];

    loadFromLast();

    printf("\n");

    while (!continue_running) {
        printf("===== Inventory management system ===== \n");
        printf("   List of actions: \n");
        printf("---------------------- \n");
        printf("| 1 | View item      |\n");
        printf("| 2 | Add item       |\n");
        printf("| 3 | Update item    |\n");
        printf("| 4 | Delete item    | \n");
        printf("| 0 | Exit program   | \n");
        printf("---------------------- \n");
        printf("What action do you want to perform? \n");

        while (fgets(input, sizeof(input), stdin)) {
            action = strtol(input, &p, 10);
            if (p == input || *p != '\n') {
                printf("Invalid input for action entered. \n");
            } else {
                fflush(stdin);
                switch (action) {
                    case 0:
                        saveSession();
                        printf("Exiting. \n");
                        continue_running = 1;
                        break;
                    case 1:
                        //  todo: view item
                        printf("Viewing item. \n");
                        printf("To view all items, type \"all\"\n");
                        printf("To view a specific item, type the name of the item. \n");
                        scanf("%10[0-9a-zA-Z ]", input);
                        viewItem(input);
                        break;
                    case 2:
                        //  todo: add item
                        printf("Adding item. \n");
                        addItem();
                        break;
                    case 3:
                        //  todo: update item
                        printf("Updating item. \n");
                        updateItem();
                        break;
                    case 4:
                        //  todo: delete item
                        printf("Deleting item. \n");
                        printf("To delete all items, type \"all\"\n");
                        printf("To delete a specific item, type the name of the item. \n");
                        scanf("%10[0-9a-zA-Z ]", &input);
                        deleteItem(input);
                        break;
                    default:
                        printf("No valid action entered. \n");
                        break;
                }
                fflush(stdin);
            }
            break;
        }
    }

    return 0;
}

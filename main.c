#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src\inventory_manager.h"



// Red \033[0;31m
// Green \033[0;32m
// Yellow \033[0;33m
// Blue \033[0;34m
// Purple \033[0;35m
// Cyan \033[0;36m
// White \033[0;37m

int main(void) {
    char *p;
    unsigned short action;
    unsigned short continue_running = 0;
    char input[128];
    unsigned short isInvalid = 0;

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
        printf("What action do you want to perform?");
        isInvalid ? printf("\033[1;31m Invalid input for action entered ! \033[0;37m\n") : printf("\n");

        while (fgets(input, sizeof(input), stdin)) {
            action = strtol(input, &p, 10);
            if (p == input || *p != '\n') {
                isInvalid = 1;
                system("cls");
            } else {
                isInvalid = 0;
                fflush(stdin);
                switch (action) {
                    case 0:
                        saveSession();
                        printf("Exiting. \n");
                        continue_running = 1;
                        break;
                    case 1:
                        system("cls");
                        printf("\033[0;33m%s\033[0;37m \n","Viewing item");
                        printf("To view all items, type \"all\"\n");
                        printf("To view a specific item, type the name of the item. \n");
                        scanf("%[0-9a-zA-Z ]", input);
                        viewItem(input);
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        system("cls");
                        printf("\033[0;33m%s\033[0;37m \n","Adding item");
                        addItem();
                        break;
                    case 3:
                        system("cls");
                        printf("\033[0;33m%s\033[0;37m \n", "Updating item");
                        updateItem();
                        break;
                    case 4:
                        system("cls");
                        printf("\033[0;33m%s\033[0;37m  \n","Deleting item");
                        printf("To delete all items, type \"all\"\n");
                        printf("To delete a specific item, type the name of the item. \n");
                        scanf("%[0-9a-zA-Z ]", &input);
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

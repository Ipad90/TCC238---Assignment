#include <stdio.h>

#include "src\inventory_manager.h"
#include "src\util.h"

int main(void) {
    unsigned short input;
    unsigned short continue_running = 0;
    char config_name[255];
    char config_value[255];

    while (!continue_running) {
        printf("What action do you want to perform? \n");
        scanf("%d", &input);

        switch (input) {
            case 0:
                printf("Exiting. \n");
                continue_running = 1;
                break;
            case 1:
                printf("Viewing item. \n");
                //  todo: view item
                viewItem();
                break;
            case 2:
                printf("Adding item. \n");
                addItem();
                //  todo: add item
                break;
            case 3:
                printf("Updating item. \n");
                //  todo: update item
                break;
            case 4:
                printf("Deleting item. \n");
                //  todo: delete item
                break;
            default:
                printf("No valid action entered. \n");
                //  just loop back
                break;
        }
        printf("\n");
    }

    return 0;
}

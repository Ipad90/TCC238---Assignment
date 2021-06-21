#include <stdio.h>
#include "file_handler.h"

struct ConfigDetails {
    char config_name[255];
    char config_value[255];
};

void update_config(char config_name[255], char config_value[255]);

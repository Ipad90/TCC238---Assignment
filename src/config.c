#include "config.h"

void update_config(char config_name[255], char config_value[255])
{
    char value[511];
    strcat(value, config_name);
    strcat(value, ",");
    strcat(value, config_value);
    add_to_file(value);
}

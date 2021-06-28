#include "colour_print.h"

int red(char *str, ...)
{
    printf("\033[0;31m");
    va_list vl;
    int i = 0, j = 0;
    char buff[100] = {0}, tmp[20];
    char *str_arg;

    va_start(vl, str);
    while (str && str[i])
    {
        if (str[i] == '%')
        {
            i++;
            switch (str[i])
            {
            /* Convert char */
            case 'c':
            {
                buff[j] = (char)va_arg(vl, int);
                j++;
                break;
            }
            /* Convert decimal */
            case 'd':
            {
                _itoa(va_arg(vl, int), tmp, 10);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert hex */
            case 'x':
            {
                _itoa(va_arg(vl, int), tmp, 16);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert octal */
            case 'o':
            {
                _itoa(va_arg(vl, int), tmp, 8);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* copy string */
            case 's':
            {
                str_arg = va_arg(vl, char *);
                strcpy(&buff[j], str_arg);
                j += strlen(str_arg);
                break;
            }
            }
        }
        else
        {
            buff[j] = str[i];
            j++;
        }
        i++;
    }
    fwrite(buff, j, 1, stdout);
    va_end(vl);
    printf("\033[0;37m");
    return j;
}

int lightRed(char *str, ...)
{
    printf("\033[1;31m");
    va_list vl;
    int i = 0, j = 0;
    char buff[100] = {0}, tmp[20];
    char *str_arg;

    va_start(vl, str);
    while (str && str[i])
    {
        if (str[i] == '%')
        {
            i++;
            switch (str[i])
            {
            /* Convert char */
            case 'c':
            {
                buff[j] = (char)va_arg(vl, int);
                j++;
                break;
            }
            /* Convert decimal */
            case 'd':
            {
                _itoa(va_arg(vl, int), tmp, 10);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert hex */
            case 'x':
            {
                _itoa(va_arg(vl, int), tmp, 16);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert octal */
            case 'o':
            {
                _itoa(va_arg(vl, int), tmp, 8);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* copy string */
            case 's':
            {
                str_arg = va_arg(vl, char *);
                strcpy(&buff[j], str_arg);
                j += strlen(str_arg);
                break;
            }
            }
        }
        else
        {
            buff[j] = str[i];
            j++;
        }
        i++;
    }
    fwrite(buff, j, 1, stdout);
    va_end(vl);
    printf("\033[0;37m");
    return j;
}

int green(char *str, ...)
{
    printf("\033[0;32m");
    va_list vl;
    int i = 0, j = 0;
    char buff[100] = {0}, tmp[20];
    char *str_arg;

    va_start(vl, str);
    while (str && str[i])
    {
        if (str[i] == '%')
        {
            i++;
            switch (str[i])
            {
            /* Convert char */
            case 'c':
            {
                buff[j] = (char)va_arg(vl, int);
                j++;
                break;
            }
            /* Convert decimal */
            case 'd':
            {
                _itoa(va_arg(vl, int), tmp, 10);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert hex */
            case 'x':
            {
                _itoa(va_arg(vl, int), tmp, 16);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert octal */
            case 'o':
            {
                _itoa(va_arg(vl, int), tmp, 8);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* copy string */
            case 's':
            {
                str_arg = va_arg(vl, char *);
                strcpy(&buff[j], str_arg);
                j += strlen(str_arg);
                break;
            }
            }
        }
        else
        {
            buff[j] = str[i];
            j++;
        }
        i++;
    }
    fwrite(buff, j, 1, stdout);
    va_end(vl);
    printf("\033[0;37m");
    return j;
}

int lightGreen(char *str, ...)
{
    printf("\033[1;32m");
    va_list vl;
    int i = 0, j = 0;
    char buff[100] = {0}, tmp[20];
    char *str_arg;

    va_start(vl, str);
    while (str && str[i])
    {
        if (str[i] == '%')
        {
            i++;
            switch (str[i])
            {
            /* Convert char */
            case 'c':
            {
                buff[j] = (char)va_arg(vl, int);
                j++;
                break;
            }
            /* Convert decimal */
            case 'd':
            {
                _itoa(va_arg(vl, int), tmp, 10);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert hex */
            case 'x':
            {
                _itoa(va_arg(vl, int), tmp, 16);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert octal */
            case 'o':
            {
                _itoa(va_arg(vl, int), tmp, 8);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* copy string */
            case 's':
            {
                str_arg = va_arg(vl, char *);
                strcpy(&buff[j], str_arg);
                j += strlen(str_arg);
                break;
            }
            }
        }
        else
        {
            buff[j] = str[i];
            j++;
        }
        i++;
    }
    fwrite(buff, j, 1, stdout);
    va_end(vl);
    printf("\033[0;37m");
    return j;
}

int yellow(char *str, ...)
{
    printf("\033[0;33m");
    va_list vl;
    int i = 0, j = 0;
    char buff[100] = {0}, tmp[20];
    char *str_arg;

    va_start(vl, str);
    while (str && str[i])
    {
        if (str[i] == '%')
        {
            i++;
            switch (str[i])
            {
            /* Convert char */
            case 'c':
            {
                buff[j] = (char)va_arg(vl, int);
                j++;
                break;
            }
            /* Convert decimal */
            case 'd':
            {
                _itoa(va_arg(vl, int), tmp, 10);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert hex */
            case 'x':
            {
                _itoa(va_arg(vl, int), tmp, 16);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert octal */
            case 'o':
            {
                _itoa(va_arg(vl, int), tmp, 8);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* copy string */
            case 's':
            {
                str_arg = va_arg(vl, char *);
                strcpy(&buff[j], str_arg);
                j += strlen(str_arg);
                break;
            }
            }
        }
        else
        {
            buff[j] = str[i];
            j++;
        }
        i++;
    }
    fwrite(buff, j, 1, stdout);
    va_end(vl);
    printf("\033[0;37m");
    return j;
}

int lightYellow(char *str, ...)
{
    printf("\033[1;33m");
    va_list vl;
    int i = 0, j = 0;
    char buff[100] = {0}, tmp[20];
    char *str_arg;

    va_start(vl, str);
    while (str && str[i])
    {
        if (str[i] == '%')
        {
            i++;
            switch (str[i])
            {
            /* Convert char */
            case 'c':
            {
                buff[j] = (char)va_arg(vl, int);
                j++;
                break;
            }
            /* Convert decimal */
            case 'd':
            {
                _itoa(va_arg(vl, int), tmp, 10);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert hex */
            case 'x':
            {
                _itoa(va_arg(vl, int), tmp, 16);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert octal */
            case 'o':
            {
                _itoa(va_arg(vl, int), tmp, 8);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* copy string */
            case 's':
            {
                str_arg = va_arg(vl, char *);
                strcpy(&buff[j], str_arg);
                j += strlen(str_arg);
                break;
            }
            }
        }
        else
        {
            buff[j] = str[i];
            j++;
        }
        i++;
    }
    fwrite(buff, j, 1, stdout);
    va_end(vl);
    printf("\033[0;37m");
    return j;
}

int blue(char *str, ...)
{
    printf("\033[0;34m");
    va_list vl;
    int i = 0, j = 0;
    char buff[100] = {0}, tmp[20];
    char *str_arg;

    va_start(vl, str);
    while (str && str[i])
    {
        if (str[i] == '%')
        {
            i++;
            switch (str[i])
            {
            /* Convert char */
            case 'c':
            {
                buff[j] = (char)va_arg(vl, int);
                j++;
                break;
            }
            /* Convert decimal */
            case 'd':
            {
                _itoa(va_arg(vl, int), tmp, 10);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert hex */
            case 'x':
            {
                _itoa(va_arg(vl, int), tmp, 16);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert octal */
            case 'o':
            {
                _itoa(va_arg(vl, int), tmp, 8);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* copy string */
            case 's':
            {
                str_arg = va_arg(vl, char *);
                strcpy(&buff[j], str_arg);
                j += strlen(str_arg);
                break;
            }
            }
        }
        else
        {
            buff[j] = str[i];
            j++;
        }
        i++;
    }
    fwrite(buff, j, 1, stdout);
    va_end(vl);
    printf("\033[0;37m");
    return j;
}

int lightBlue(char *str, ...)
{
    printf("\033[1;34m");
    va_list vl;
    int i = 0, j = 0;
    char buff[100] = {0}, tmp[20];
    char *str_arg;

    va_start(vl, str);
    while (str && str[i])
    {
        if (str[i] == '%')
        {
            i++;
            switch (str[i])
            {
            /* Convert char */
            case 'c':
            {
                buff[j] = (char)va_arg(vl, int);
                j++;
                break;
            }
            /* Convert decimal */
            case 'd':
            {
                _itoa(va_arg(vl, int), tmp, 10);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert hex */
            case 'x':
            {
                _itoa(va_arg(vl, int), tmp, 16);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert octal */
            case 'o':
            {
                _itoa(va_arg(vl, int), tmp, 8);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* copy string */
            case 's':
            {
                str_arg = va_arg(vl, char *);
                strcpy(&buff[j], str_arg);
                j += strlen(str_arg);
                break;
            }
            }
        }
        else
        {
            buff[j] = str[i];
            j++;
        }
        i++;
    }
    fwrite(buff, j, 1, stdout);
    va_end(vl);
    printf("\033[0;37m");
    return j;
}

int purple(char *str, ...)
{
    printf("\033[0;35m");
    va_list vl;
    int i = 0, j = 0;
    char buff[100] = {0}, tmp[20];
    char *str_arg;

    va_start(vl, str);
    while (str && str[i])
    {
        if (str[i] == '%')
        {
            i++;
            switch (str[i])
            {
            /* Convert char */
            case 'c':
            {
                buff[j] = (char)va_arg(vl, int);
                j++;
                break;
            }
            /* Convert decimal */
            case 'd':
            {
                _itoa(va_arg(vl, int), tmp, 10);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert hex */
            case 'x':
            {
                _itoa(va_arg(vl, int), tmp, 16);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert octal */
            case 'o':
            {
                _itoa(va_arg(vl, int), tmp, 8);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* copy string */
            case 's':
            {
                str_arg = va_arg(vl, char *);
                strcpy(&buff[j], str_arg);
                j += strlen(str_arg);
                break;
            }
            }
        }
        else
        {
            buff[j] = str[i];
            j++;
        }
        i++;
    }
    fwrite(buff, j, 1, stdout);
    va_end(vl);
    printf("\033[0;37m");
    return j;
}

int lightPurple(char *str, ...)
{
    printf("\033[1;35m");
    va_list vl;
    int i = 0, j = 0;
    char buff[100] = {0}, tmp[20];
    char *str_arg;

    va_start(vl, str);
    while (str && str[i])
    {
        if (str[i] == '%')
        {
            i++;
            switch (str[i])
            {
            /* Convert char */
            case 'c':
            {
                buff[j] = (char)va_arg(vl, int);
                j++;
                break;
            }
            /* Convert decimal */
            case 'd':
            {
                _itoa(va_arg(vl, int), tmp, 10);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert hex */
            case 'x':
            {
                _itoa(va_arg(vl, int), tmp, 16);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert octal */
            case 'o':
            {
                _itoa(va_arg(vl, int), tmp, 8);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* copy string */
            case 's':
            {
                str_arg = va_arg(vl, char *);
                strcpy(&buff[j], str_arg);
                j += strlen(str_arg);
                break;
            }
            }
        }
        else
        {
            buff[j] = str[i];
            j++;
        }
        i++;
    }
    fwrite(buff, j, 1, stdout);
    va_end(vl);
    printf("\033[0;37m");
    return j;
}

int cyan(char *str, ...)
{
    printf("\033[0;36m");
    va_list vl;
    int i = 0, j = 0;
    char buff[100] = {0}, tmp[20];
    char *str_arg;

    va_start(vl, str);
    while (str && str[i])
    {
        if (str[i] == '%')
        {
            i++;
            switch (str[i])
            {
            /* Convert char */
            case 'c':
            {
                buff[j] = (char)va_arg(vl, int);
                j++;
                break;
            }
            /* Convert decimal */
            case 'd':
            {
                _itoa(va_arg(vl, int), tmp, 10);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert hex */
            case 'x':
            {
                _itoa(va_arg(vl, int), tmp, 16);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert octal */
            case 'o':
            {
                _itoa(va_arg(vl, int), tmp, 8);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* copy string */
            case 's':
            {
                str_arg = va_arg(vl, char *);
                strcpy(&buff[j], str_arg);
                j += strlen(str_arg);
                break;
            }
            }
        }
        else
        {
            buff[j] = str[i];
            j++;
        }
        i++;
    }
    fwrite(buff, j, 1, stdout);
    va_end(vl);
    printf("\033[0;37m");
    return j;
}

int lightCyan(char *str, ...)
{
    printf("\033[1;36m");
    va_list vl;
    int i = 0, j = 0;
    char buff[100] = {0}, tmp[20];
    char *str_arg;

    va_start(vl, str);
    while (str && str[i])
    {
        if (str[i] == '%')
        {
            i++;
            switch (str[i])
            {
            /* Convert char */
            case 'c':
            {
                buff[j] = (char)va_arg(vl, int);
                j++;
                break;
            }
            /* Convert decimal */
            case 'd':
            {
                _itoa(va_arg(vl, int), tmp, 10);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert hex */
            case 'x':
            {
                _itoa(va_arg(vl, int), tmp, 16);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* Convert octal */
            case 'o':
            {
                _itoa(va_arg(vl, int), tmp, 8);
                strcpy(&buff[j], tmp);
                j += strlen(tmp);
                break;
            }
            /* copy string */
            case 's':
            {
                str_arg = va_arg(vl, char *);
                strcpy(&buff[j], str_arg);
                j += strlen(str_arg);
                break;
            }
            }
        }
        else
        {
            buff[j] = str[i];
            j++;
        }
        i++;
    }
    fwrite(buff, j, 1, stdout);
    va_end(vl);
    printf("\033[0;37m");
    return j;
}
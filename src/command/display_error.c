/*
** EPITECH PROJECT, 2022
** command/display_error.c
** File description:
** Displays an error from a error message and the typed string
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

static void write_char(char const c)
{
    write(2, &c, 1);
}

int command_display_error(char const *typed, char const *message)
{
    if (message == NULL)
        return 0;
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] == '@' && message[i + 1] == '@' && typed != NULL) {
            write(2, typed, LEN(typed));
            i++;
        } else {
            write_char(message[i]);
        }
    }
    return 0;
}

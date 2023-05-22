/*
** EPITECH PROJECT, 2022
** command/create.c
** File description:
** Creates a command
*/

#include "my.h"
#include "script.h"
#include <stdlib.h>

static command_t invalid_command(char const *typed, command_t command)
{
    if (command.ary != NULL)
        my_free_char_2d(command.ary);
    command.ary = NULL;
    command.comment = 1;
    command.length = 0;
    return command;
}

command_t command_create(char const *typed)
{
    int length = 0;
    command_t command = {NULL, 1, 0};

    if (typed == NULL)
        return invalid_command(typed, command);
    command.ary = my_str_to_array(typed, CMD_SEPARATORS);
    if (command.ary == NULL) {
        command_display_error(typed, ER_MSG_CANTCMD);
        return invalid_command(typed, command);
    }
    command.comment = 0;
    for (length = 0; command.ary[length] != NULL; length++);
    command.length = length;
    return command;
}

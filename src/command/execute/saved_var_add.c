/*
** EPITECH PROJECT, 2022
** command/execute/saved_var_add.c
** File description:
** Adds a value to a saved var
*/

#include "my.h"
#include "script.h"
#include "struct.h"
#include <stdlib.h>

static int change_var(int const var_id, int const value)
{
    if (var_id < 0 || SAVED_VARIABLES <= var_id)
        return 0;
    GAME.saved_variables[var_id] += value;
    return 1;
}

int command_execute_saved_var_add(command_t command, event_t *event)
{
    int var_id = 0;
    int value = 0;

    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 3)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 3)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    var_id = command_get_argument(command.ary[1], event);
    value = command_get_argument(command.ary[2], event);
    return change_var(var_id, value);
}

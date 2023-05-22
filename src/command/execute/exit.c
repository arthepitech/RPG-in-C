/*
** EPITECH PROJECT, 2022
** command/execute/exit.c
** File description:
** Displays the arguments
*/

#include "my.h"
#include "script.h"
#include "struct.h"
#include <stdlib.h>

int command_execute_exit(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 1)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 1)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    GAME.window_force_close = sfTrue;
    return 1;
}

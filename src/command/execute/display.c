/*
** EPITECH PROJECT, 2022
** command/execute/display.c
** File description:
** Displays the values associated with the arguments
*/

#include "const.h"
#include "event.h"
#include "my.h"
#include "script.h"
#include <stdlib.h>

static void display_argument(event_t *event, char const *arg)
{
    if (my_strcmp(arg, "PLAYER_MAX"))
        return my_putint(PLAYER_MAX);
    my_putint(command_get_argument(arg, event));
}

int command_execute_display(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 2)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    for (int i = 1; command.ary[i] != NULL; i++)
        display_argument(event, command.ary[i]);
    my_putchar(LINEBREAK);
    return 1;
}

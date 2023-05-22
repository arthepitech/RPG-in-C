/*
** EPITECH PROJECT, 2022
** command/execute/set_view.c
** File description:
** Changes the view type of an event
*/

#include "event.h"
#include "my.h"
#include "script.h"
#include <stdlib.h>

static int set_view(event_t *event, int const view)
{
    event->view = view;
    return 1;
}

int command_execute_set_view(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 2)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 2)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    if (event == NULL)
        return 0;
    return set_view(event, command_get_argument(command.ary[1], event));
}

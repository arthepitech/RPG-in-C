/*
** EPITECH PROJECT, 2022
** command/execute/move_event.c
** File description:
** Move the event on the map
*/

#include "event.h"
#include "my.h"
#include "script.h"
#include <stdlib.h>

static int move_event(event_t *event, float const x, float const y)
{
    event->position.x += x;
    event->position.y += y;
    return 1;
}

int command_execute_move_event(command_t command, event_t *event)
{
    sfVector2f coordinates = {0, 0};

    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 3)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 3)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    if (event == NULL)
        return 0;
    coordinates.x = command_get_argument(command.ary[1], event);
    coordinates.y = command_get_argument(command.ary[2], event);
    return move_event(event, coordinates.x, coordinates.y);
}

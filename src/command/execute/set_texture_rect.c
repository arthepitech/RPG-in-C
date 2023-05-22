/*
** EPITECH PROJECT, 2022
** command/execute/set_texture_rect.c
** File description:
** Change the texture_rect of an event's tile
*/

#include "event.h"
#include "my.h"
#include "script.h"
#include <stdlib.h>

static int set_texture_rect(event_t *event, int const x, int const y)
{
    if (x >= 0)
        event->tile->texture_rect.x = x;
    if (y >= 0)
        event->tile->texture_rect.y = y;
    return 1;
}

int command_execute_set_texture_rect(command_t command, event_t *event)
{
    sfVector2i coordinates = {0, 0};

    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 3)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 3)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    if (event == NULL || event->tile == NULL)
        return 0;
    coordinates.x = command_get_argument(command.ary[1], event);
    coordinates.y = command_get_argument(command.ary[2], event);
    return set_texture_rect(event, coordinates.x, coordinates.y);
}

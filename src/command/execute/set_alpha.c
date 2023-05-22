/*
** EPITECH PROJECT, 2022
** command/execute/set_alpha.c
** File description:
** Changes the transparency of an event, from 0 to 100
*/

#include "event.h"
#include "my.h"
#include "script.h"
#include <stdlib.h>

static int set_alpha(event_t *event, float alpha)
{
    alpha = (alpha * 255) / 100;
    if (alpha < 0)
        alpha = 0;
    if (alpha > 255)
        alpha = 255;
    event->tile->palette[0].a = (int)alpha;
    event->tile->palette[1].a = (int)alpha;
    event->tile->palette[2].a = (int)alpha;
    return 1;
}

int command_execute_set_alpha(command_t command, event_t *event)
{
    float value = 0;

    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 2)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 2)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    if (event == NULL || event->tile == NULL || event->tile->palette == NULL)
        return 0;
    value = command_get_argument(command.ary[1], event);
    return set_alpha(event, value);
}

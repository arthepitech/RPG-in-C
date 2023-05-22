/*
** EPITECH PROJECT, 2022
** command/execute/reset_palette.c
** File description:
** Set palette and palette_pointed to NULL
*/

#include "event.h"
#include "my.h"
#include "script.h"
#include <stdlib.h>

static int reset_palette(event_t *event)
{
    if (event->tile->palette != NULL)
        free(event->tile->palette);
    event->tile->palette = NULL;
    event->tile->palette_pointed = NULL;
    return 1;
}

int command_execute_reset_palette(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length > 1)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    if (event == NULL || event->tile == NULL)
        return 0;
    return reset_palette(event);
}

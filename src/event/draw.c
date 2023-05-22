/*
** EPITECH PROJECT, 2022
** event/draw.c
** File description:
** Displays an event on screen
*/

#include "event.h"
#include <stdlib.h>

int event_draw(event_t *event)
{
    if (event == NULL)
        return 0;
    event->tile->position.x = event->position.x;
    event->tile->position.y = event->position.y;
    tile_draw(event->tile);
    return 1;
}

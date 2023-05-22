/*
** EPITECH PROJECT, 2022
** event/create.c
** File description:
** Creates an event
*/

#include "event.h"
#include <stdlib.h>

static void set_default_values(event_t *event)
{
    for (int i = 0; i < CALL_TOTAL_SIZE; i++)
        for (int j = 0; j < MAX_SCRIPTS_PER_CALLS; j++)
            event->script[i][j] = NULL;
    for (int i = 0; i < EVENT_VAR_SIZE; i++)
        event->variable[i] = 0;
    event->position.x = 0;
    event->position.y = 0;
    event->layer = 0;
    event->view = 0;
}

event_t *event_create(void)
{
    event_t *event = NULL;

    event = malloc(sizeof(event_t));
    if (event == NULL)
        return NULL;
    event->tile = tile_create();
    if (event->tile == NULL) {
        free(event);
        return NULL;
    }
    set_default_values(event);
    return event;
}

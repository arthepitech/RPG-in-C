/*
** EPITECH PROJECT, 2022
** event/destroy.c
** File description:
** Destroys an event
*/

#include "event.h"
#include <stdlib.h>

static void destroy_scripts(event_t *event)
{
    for (int i = 0; i < CALL_TOTAL_SIZE; i++)
        for (int j = 0; j < MAX_SCRIPTS_PER_CALLS; j++)
            script_destroy(event->script[i][j]);
}

event_t *event_destroy(event_t *event)
{
    if (event == NULL)
        return NULL;
    destroy_scripts(event);
    if (event->tile != NULL)
        tile_destroy(event->tile);
    free(event);
    return NULL;
}

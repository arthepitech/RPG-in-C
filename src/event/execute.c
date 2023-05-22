/*
** EPITECH PROJECT, 2022
** event/execute.c
** File description:
** Executes scripts linked to an event
*/

#include "event.h"
#include <stdlib.h>

int event_execute(event_t *event, int const call_idx)
{
    int returned = 0;

    if (event == NULL || call_idx < 0 || CALL_TOTAL_SIZE <= call_idx)
        return 0;
    for (int i = 0; i < MAX_SCRIPTS_PER_CALLS; i++)
        returned += script_execute(event->script[call_idx][i], event);
    return returned;
}

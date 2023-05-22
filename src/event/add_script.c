/*
** EPITECH PROJECT, 2022
** event/add_script.c
** File description:
** Adds a script to an already existing event
*/

#include "event.h"
#include "my.h"
#include <stdlib.h>

int event_add_script(event_t *event, char const *name, int const call_idx)
{
    script_t *script = NULL;

    if (event == NULL || call_idx < 0 || CALL_TOTAL_SIZE <= call_idx)
        return -1;
    script = script_get(name);
    if (script == NULL)
        return -1;
    for (int i = 0; i < MAX_SCRIPTS_PER_CALLS; i++) {
        if (event->script[call_idx][i] == NULL) {
            event->script[call_idx][i] = script;
            return i;
        }
    }
    return -1;
}

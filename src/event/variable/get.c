/*
** EPITECH PROJECT, 2022
** event/variable_get.c
** File description:
** Gets the value of a event's variable
*/

#include "event.h"
#include <stdlib.h>

float event_variable_get(event_t const *event, int const var_id)
{
    if (event == NULL)
        return 0;
    if (var_id < 0 || EVENT_VAR_SIZE <= var_id)
        return 0;
    return event->variable[var_id];
}

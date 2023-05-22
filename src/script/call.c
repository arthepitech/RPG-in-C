/*
** EPITECH PROJECT, 2022
** script/call.c
** File description:
** Gets a script, executes it, then destroys it
*/

#include "script.h"
#include <stdlib.h>

int script_call(char const *name, event_t *event)
{
    int returned = 0;
    script_t *script = NULL;

    if (name == NULL)
        return 0;
    script = script_get(name);
    if (script == NULL)
        return 0;
    returned = script_execute(script, event);
    script_destroy(script);
    return returned;
}

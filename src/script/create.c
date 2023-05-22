/*
** EPITECH PROJECT, 2022
** script/create.c
** File description:
** Creates a script
*/

#include "script.h"
#include <stdlib.h>

script_t *script_create(void)
{
    script_t *script = NULL;

    script = malloc(sizeof(script_t));
    if (script == NULL)
        return NULL;
    script->commands = NULL;
    script->length = 0;
    return script;
}

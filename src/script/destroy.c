/*
** EPITECH PROJECT, 2022
** script/destroy.c
** File description:
** Destroys a script
*/

#include "script.h"
#include <stdlib.h>

static void free_commands(script_t *script)
{
    if (script->commands == NULL)
        return;
    for (int i = 0; i < script->length; i++)
        command_destroy(script->commands[i]);
    free(script->commands);
}

script_t *script_destroy(script_t *script)
{
    if (script == NULL)
        return NULL;
    free_commands(script);
    free(script);
    return NULL;
}

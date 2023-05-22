/*
** EPITECH PROJECT, 2022
** script/get.c
** File description:
** Searchs a script in files
*/

#include "filepaths.h"
#include "files.h"
#include "my.h"
#include "script.h"
#include <stdlib.h>

static void place_command(command_t *command, char const *typed)
{
    command_t new_command = command_create(typed);

    command->ary = new_command.ary;
    command->comment = new_command.comment;
    command->length = new_command.length;
}

static void script_extract(script_t *script, char * const *ary)
{
    int length = 0;

    for (length = 0; ary[length] != NULL; length++);
    script->commands = malloc(sizeof(command_t) * length);
    if (script->commands == NULL)
        return;
    for (int i = 0; i < length; i++)
        place_command(&script->commands[i], ary[i]);
    script->length = length;
}

script_t *script_get(char const *name)
{
    char **ary = NULL;
    script_t *script = NULL;

    if (name == NULL)
        return NULL;
    script = script_create();
    if (script == NULL)
        return NULL;
    ary = path_form_and_convert(name, PATH_SCRIPTS);
    if (ary == NULL) {
        script_destroy(script);
        return NULL;
    }
    script_extract(script, ary);
    my_free_char_2d(ary);
    return script;
}

/*
** EPITECH PROJECT, 2022
** event/extract_script.c
** File description:
** Required for event/get.c
*/

#include "event.h"
#include "filepaths.h"
#include "my.h"
#include "script.h"
#include <stdlib.h>

static script_t *command_script(char const *typed)
{
    command_t command = command_create(typed);
    script_t *script = NULL;

    script = script_create();
    if (script == NULL) {
        command_destroy(command);
        return NULL;
    }
    script->commands = malloc(sizeof(command_t));
    if (script->commands == NULL) {
        command_destroy(command);
        return script;
    }
    script->commands[0].ary = command.ary;
    script->commands[0].comment = command.comment;
    script->commands[0].length = command.length;
    script->length = 1;
    return script;
}

static void manage_adding(event_t *event, char * const *ary, int const call)
{
    int length = 0;
    script_t *script = NULL;

    for (length = 0; ary[length] != NULL; length++);
    if (!my_strcmp(ary[1], COMMAND_INSTEAD_OF_SCRIPT))
        event_add_script(event, ary[1], call);
    if (length < 3)
        return;
    script = command_script(ary[2]);
    if (script == NULL)
        return;
    for (int i = 0; i < MAX_SCRIPTS_PER_CALLS; i++) {
        if (event->script[call][i] == NULL) {
            event->script[call][i] = script;
            return;
        }
    }
}

static void extract_informations(event_t *event, char * const *ary)
{
    if (ary == NULL || ary[0] == NULL || ary[1] == NULL)
        return;
    for (int i = 0; i < CALL_TOTAL_SIZE; i++) {
        if (my_strcmp(ary[0], CALL_KEYWORDS[i]))
            manage_adding(event, ary, i);
    }
}

void event_extract_script(event_t *event, char const *str)
{
    char **ary = NULL;

    if (event == NULL || str == NULL)
        return;
    ary = my_str_to_array(str, EVENT_SCRIPT_SEPARATORS);
    if (ary == NULL)
        return;
    extract_informations(event, ary);
    my_free_char_2d(ary);
}

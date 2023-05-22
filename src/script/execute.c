/*
** EPITECH PROJECT, 2022
** script/execute.c
** File description:
** Executes a script
*/

#include "my.h"
#include "script.h"
#include <stdlib.h>

static int get_condition_id(char const *str)
{
    int id = 0;

    if (str == NULL)
        return -1;
    for (; CONDITION_FUNCTIONS[id] != NULL && CONDITION_KEYS[id] != NULL; id++)
        if (my_strcmp(CONDITION_KEYS[id], str))
            return id;
    return -1;
}

static int test_condition(command_t command, event_t *event, int const reverse)
{
    int is_true = 0;
    int condition_id = get_condition_id(command.ary[1]);

    if (condition_id < 0)
        return command_display_error(command.ary[1], ER_MSG_INVCMD);
    is_true = CONDITION_FUNCTIONS[condition_id](command, event);
    if ((is_true + reverse) % 2 == 1)
        return 1;
    return 0;
}

static int execute_cmd(script_t *script, event_t *event,
int const idx, int const length)
{
    if (idx >= length || script->commands[idx].ary == NULL)
        return 0;
    if (my_strcmp(script->commands[idx].ary[0], CMD_CONDITION_UNLESS))
        if (!test_condition(script->commands[idx], event, 1))
            return 1;
    if (my_strcmp(script->commands[idx].ary[0], CMD_CONDITION_IF))
        if (!test_condition(script->commands[idx], event, 0))
            return 1;
    command_execute(script->commands[idx], event);
    return 0;
}

int script_execute(script_t *script, event_t *event)
{
    if (script == NULL)
        return 0;
    if (script->commands == NULL)
        return 1;
    for (int i = 0; i < script->length; i++)
        i += execute_cmd(script, event, i, script->length);
    return 1;
}

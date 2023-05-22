/*
** EPITECH PROJECT, 2022
** command/execute.c
** File description:
** Executes a command
*/

#include "event.h"
#include "my.h"
#include "script.h"
#include <stdlib.h>

int command_execute(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 0 || command.comment)
        return 0;
    for (int i = 0; EXECUTE_FUNCTIONS[i] != NULL; i++) {
        if (EXECUTE_KEYS[i] == NULL)
            return 0;
        if (my_strcmp(command.ary[0], EXECUTE_KEYS[i]))
            return EXECUTE_FUNCTIONS[i](command, event);
    }
    return 0;
}

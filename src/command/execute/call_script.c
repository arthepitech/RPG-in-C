/*
** EPITECH PROJECT, 2022
** command/execute/call_script.c
** File description:
** Call another script
*/

#include "const.h"
#include "event.h"
#include "my.h"
#include "script.h"
#include <stdlib.h>

static char *add_segment(char *str, char const *segment)
{
    char *str2 = NULL;
    char *str3 = NULL;

    if (str == NULL)
        return NULL;
    if (segment == NULL)
        return str;
    str2 = my_strcat(str, CMD_SEPARATORS);
    if (str2 == NULL)
        return str;
    str3 = my_strcat(str2, segment);
    free(str2);
    if (str3 == NULL)
        return str;
    free(str);
    return str3;
}

static int call_script(command_t command, event_t *event)
{
    char *str = command.ary[1];

    if (str == NULL)
        return 0;
    for (int i = 2; command.ary[i] != NULL; i++) {
        str = add_segment(str, command.ary[i]);
        if (str == NULL)
            return 0;
    }
    return script_call(str, event);
}

int command_execute_call_script(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 2)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    return call_script(command, event);
}

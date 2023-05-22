/*
** EPITECH PROJECT, 2022
** script/condition/is_player_connected.c
** File description:
** Check is a player is connected
*/

#include "const.h"
#include "event.h"
#include "my.h"
#include "script.h"
#include "struct.h"
#include <stdlib.h>

static int comparison(event_t *event, float const value1, float const value2,
char const *operator)
{
    if (my_strcmp(operator, "="))
        return (value1 == value2);
    if (my_strcmp(operator, "=="))
        return (value1 == value2);
    if (my_strcmp(operator, "<"))
        return (value1 < value2);
    if (my_strcmp(operator, ">"))
        return (value1 > value2);
    if (my_strcmp(operator, "<="))
        return (value1 <= value2);
    if (my_strcmp(operator, ">="))
        return (value1 >= value2);
    return 0;
}

int script_condition_comparison(command_t command, event_t *event)
{
    float value1 = 0;
    float value2 = 0;

    if (command.ary == NULL || command.length < 2)
        return 0;
    if (command.length < 5)
        return command_display_error(command.ary[1], ER_CMD_TOOFEW);
    if (command.length > 5)
        return command_display_error(command.ary[1], ER_CMD_TOOMANY);
    value1 = command_get_argument(command.ary[2], event);
    value2 = command_get_argument(command.ary[4], event);
    return comparison(event, value1, value2, command.ary[3]);
}

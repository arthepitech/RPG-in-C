/*
** EPITECH PROJECT, 2022
** command/execute/add_music.c
** File description:
** Adds an equipment
*/

#include "const.h"
#include "event.h"
#include "items.h"
#include "script.h"
#include <stdlib.h>

static int add_music(char const *name)
{
    return music_add(name);
}

int command_execute_add_music(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 2)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 2)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    return add_music(command.ary[1]);
}

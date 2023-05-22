/*
** EPITECH PROJECT, 2022
** command/execute/save_load.c
** File description:
** Displays the arguments
*/

#include "calls.h"
#include "filepaths.h"
#include "my.h"
#include "script.h"
#include "struct.h"
#include <stdlib.h>

int command_execute_save_load(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 1)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 1)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    return save_load(FILE_SAVE);
}

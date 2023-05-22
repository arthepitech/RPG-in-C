/*
** EPITECH PROJECT, 2022
** command/execute/change_fullscreen.c
** File description:
** Displays the arguments
*/

#include "my.h"
#include "script.h"
#include "struct.h"
#include <stdlib.h>

int command_execute_change_fullscreen(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 1)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 1)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    sfRenderWindow_destroy(GAME.window);
    window_create((GAME.window_fullscreen + 1) % 2);
    return 1;
}

/*
** EPITECH PROJECT, 2022
** script/condition/is_player_connected.c
** File description:
** Check is a player is connected
*/

#include "const.h"
#include "script.h"
#include "struct.h"
#include <stdlib.h>

static int is_player(event_t *event, int player)
{
    if (player > 0)
        player -= 1;
    if (player < 0 || PLAYER_MAX <= player)
        return 0;
    if (GAME.player[player].connected)
        return 1;
    return 0;
}

int script_condition_is_player_connected(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 2)
        return 0;
    if (command.length < 3)
        return command_display_error(command.ary[1], ER_CMD_TOOFEW);
    if (command.length > 3)
        return command_display_error(command.ary[1], ER_CMD_TOOMANY);
    return is_player(event, command_get_argument(command.ary[2], event));
}

/*
** EPITECH PROJECT, 2022
** command/execute/teleport_players.c
** File description:
** Teleports players onto a new map
*/

#include "const.h"
#include "event.h"
#include "my.h"
#include "script.h"
#include "struct.h"
#include <stdlib.h>

static void teleport_players(command_t command, event_t *evt)
{
    if (GAME.map_next != NULL)
        free(GAME.map_next);
    GAME.map_next = DUP(command.ary[1]);
    GAME.map_next_position.x = command_get_argument(command.ary[2], evt);
    GAME.map_next_position.y = command_get_argument(command.ary[3], evt);
}

int command_execute_teleport_players(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 4)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 4)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    teleport_players(command, event);
    return 1;
}

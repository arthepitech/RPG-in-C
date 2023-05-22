/*
** EPITECH PROJECT, 2022
** command/execute/go_on_player.c
** File description:
** Move the event to the player's position
*/

#include "const.h"
#include "event.h"
#include "my.h"
#include "script.h"
#include "struct.h"
#include <stdlib.h>

static int go_on_player(event_t *event, int player)
{
    if (player > 0)
        player -= 1;
    if (player < 0 || PLAYER_MAX <= player)
        return 0;
    event->position.x = POSITION_OUT_OF_SCREEN.x;
    event->position.y = POSITION_OUT_OF_SCREEN.y;
    if (!GAME.player[player].connected)
        return 1;
    event->position.x = GAME.player[player].position.x;
    event->position.y = GAME.player[player].position.y;
    return 1;
}

int command_execute_go_on_player(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 2)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 2)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    if (event == NULL)
        return 0;
    return go_on_player(event, command_get_argument(command.ary[1], event));
}

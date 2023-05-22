/*
** EPITECH PROJECT, 2022
** command/execute/equip_player.c
** File description:
** Equips a player with an item
*/

#include "const.h"
#include "event.h"
#include "items.h"
#include "my.h"
#include "script.h"
#include "struct.h"
#include <stdlib.h>

static int equip_player(char const *name, int player)
{
    if (name == NULL)
        return 0;
    if (player < 0) {
        for (int i = 0; i < PLAYER_MAX; i++)
            item_equip(name, i);
        return 1;
    }
    if (player > 0)
        player -= 1;
    if (player < 0 || PLAYER_MAX <= player)
        return 0;
    return item_equip(name, player);
}

int command_execute_equip_player(command_t command, event_t *event)
{
    int player = 0;

    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 2)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 3)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    if (command.length < 3)
        return equip_player(command.ary[1], -1);
    player = command_get_argument(command.ary[2], event);
    return equip_player(command.ary[1], player);
}

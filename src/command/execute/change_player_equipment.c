/*
** EPITECH PROJECT, 2022
** command/execute/change_player_equipment.c
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

static int find_actual(int const type, char const *actual_item)
{
    for (int i = 0; GAME.inventory[type][i] != NULL; i++)
        if (my_strcmp(GAME.inventory[type][i], actual_item))
            return i;
    return 0;
}

static int item_change(int const type, int const player)
{
    char *actual_item = NULL;
    int id = 0;

    if (GAME.player[player].equipment[type] != NULL)
        actual_item = GAME.player[player].equipment[type]->file;
    if (GAME.inventory[type] == NULL || GAME.inventory[type][0] == NULL)
        return 0;
    if (actual_item != NULL)
        id = find_actual(type, actual_item);
    id += 1;
    if (GAME.inventory[type][id] == NULL)
        id = 0;
    if (GAME.player[player].equipment[type] != NULL)
        item_destroy(GAME.player[player].equipment[type]);
    GAME.player[player].equipment[type] = NULL;
    return item_equip(GAME.inventory[type][id], player);
}

static int change_player_equipment(char const *type, int player)
{
    int item_type = -1;

    if (type == NULL)
        return 0;
    for (int i = 0; ITEM_TYPE_KEYS[i] != NULL; i++)
        if (my_strcmp(type, ITEM_TYPE_KEYS[i]))
            item_type = i;
    if (player > 0)
        player -= 1;
    if (player < 0 || PLAYER_MAX <= player || item_type < 0)
        return 0;
    return item_change(item_type, player);
}

int command_execute_change_player_equipment(command_t command, event_t *event)
{
    int player = 0;

    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 3)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 3)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    player = command_get_argument(command.ary[1], event);
    return change_player_equipment(command.ary[2], player);
}

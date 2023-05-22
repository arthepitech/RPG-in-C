/*
** EPITECH PROJECT, 2022
** item/equip.c
** File description:
** Equips an item, and add it to the inventory if needed
*/

#include "const.h"
#include "items.h"
#include "my.h"
#include "struct.h"
#include <stdlib.h>

static int is_valid_player(int const player)
{
    if (player < 0)
        return 0;
    if (player >= PLAYER_MAX)
        return 0;
    return 1;
}

int item_equip(char const *name, int const player)
{
    item_t *item = NULL;

    if (name == NULL)
        return 0;
    if (!is_valid_player(player))
        return 0;
    item = item_get(name);
    if (item == NULL)
        return 0;
    if (GAME.player[player].equipment[item->type] != NULL)
        item_destroy(GAME.player[player].equipment[item->type]);
    GAME.player[player].equipment[item->type] = item;
    item_add(name);
    return 1;
}

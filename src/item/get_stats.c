/*
** EPITECH PROJECT, 2022
** item/get_stats.c
** File description:
** Gets the stats of a team
*/

#include "items.h"
#include "my.h"
#include "struct.h"
#include <stdlib.h>

static int get_item_stats(int const stat, item_t *item)
{
    if (item == NULL)
        return 0;
    return item->stats[stat];
}

static int get_player_stats(int const stat, int const player)
{
    int value = 0;

    for (int i = 0; i < ITEM_TYPE_TOTAL_SIZE; i++)
        value += get_item_stats(stat, GAME.player[player].equipment[i]);
    return value;
}

int item_get_stats(int const stat)
{
    int value = 0;

    if (stat < 0 || stat >= STAT_TOTAL_SIZE)
        return 0;
    value = BASE_STATS[stat];
    for (int i = 0; i < PLAYER_MAX; i++)
        if (GAME.player[i].connected)
            value += get_player_stats(stat, i);
    return value;
}

/*
** EPITECH PROJECT, 2022
** tick/draw/map.c
** File description:
** Displays players' screens
*/

#include "calls.h"
#include "maps.h"
#include "struct.h"
#include <stddef.h>

static int draw_player_game(int const player)
{
    if (player < 0) {
        tick_change_view(0);
        map_draw(GAME.map, 1);
    }
    if (!GAME.player[player].connected)
        return 0;
    tick_change_view(player);
    map_draw(GAME.map, player + 1);
    return 1;
}

int tick_draw_map(void)
{
    int player_connected = 0;

    for (int i = 0; i < PLAYER_MAX; i++)
        player_connected += draw_player_game(i);
    if (player_connected > 0)
        return 1;
    draw_player_game(-1);
    return 0;
}

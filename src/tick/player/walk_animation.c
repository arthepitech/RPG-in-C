/*
** EPITECH PROJECT, 2022
** tick/player/walk_animation.c
** File description:
** Updates the walk animation of a player
*/

#include "const.h"
#include "struct.h"
#include <stddef.h>

int tick_player_walk_animation(int player)
{
    int limit = 0;

    if (player < 0)
        return -1;
    player %= PLAYER_MAX;
    limit = SEC_TO_MICRO / WALKING_ANIMATION_SPEED;
    limit *= WALKING_ANIMATION_FRAMES;
    GAME.player[player].deltawalking += GAME.delta;
    while (GAME.player[player].deltawalking > limit)
        GAME.player[player].deltawalking -= limit;
    return GAME.player[player].deltawalking;
}

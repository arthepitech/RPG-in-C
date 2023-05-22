/*
** EPITECH PROJECT, 2022
** battle/is_playing.c
** File description:
** Check if notes are still in memory for players
*/

#include "battles.h"
#include "const.h"
#include <stdlib.h>

sfBool battle_is_playing(battle_t const *battle)
{
    for (int i = 0; i < PLAYER_MAX; i++) {
        if (battle->note[i] != NULL && battle->note[i][0] != NULL)
            return sfTrue;
    }
    return sfFalse;
}

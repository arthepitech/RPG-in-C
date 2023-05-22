/*
** EPITECH PROJECT, 2022
** free.c
** File description:
** Free everything needed on GAME
*/

#include "sound.h"
#include "struct.h"
#include <stddef.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Clock.h>

static void free_player(int const id)
{
    for (int i = 0; i < ITEM_TYPE_TOTAL_SIZE; i++)
        if (GAME.player[id].equipment[i] != NULL)
            item_destroy(GAME.player[id].equipment[i]);
}

static void free_inventory(int const id)
{
    if (GAME.inventory[id] == NULL)
        return;
    for (int i = 0; GAME.inventory[id][i] != NULL; i++)
        free(GAME.inventory[id][i]);
    free(GAME.inventory[id]);
}

void game_free(void)
{
    for (int i = 0; i < PLAYER_MAX; i++)
        free_player(i);
    for (int i = 0; i < ITEM_TYPE_TOTAL_SIZE; i++)
        free_inventory(i);
    if (GAME.deltaclock != NULL)
        sfClock_destroy(GAME.deltaclock);
    if (GAME.map != NULL)
        map_destroy(GAME.map);
    if (GAME.map_next != NULL)
        free(GAME.map_next);
    if (GAME.score != NULL) {
        for (int i = 0; GAME.score[i] != NULL; i++)
            free(GAME.score[i]);
        free(GAME.score);
    }
    parallax_destroy();
    bgm_free();
}

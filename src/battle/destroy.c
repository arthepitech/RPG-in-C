/*
** EPITECH PROJECT, 2022
** battle/destroy.c
** File description:
** Destroys a battle struct
*/

#include "battles.h"
#include "menus.h"
#include "tiles.h"
#include <stdlib.h>
#include <SFML/Audio.h>

static void free_for_each_player(battle_t *battle, int const player)
{
    sfSoundBuffer_destroy(battle->note_buffer[player]);
    for (int i = 0; i < NOTE_TOTAL_SIZE; i++)
        if (battle->note_sound[player][i] != NULL)
            sfSound_destroy(battle->note_sound[player][i]);
    if (battle->note[player] == NULL)
        return;
    for (int i = 0; battle->note[player][i] != NULL; i++)
        free(battle->note[player][i]);
    free(battle->note[player]);
}

battle_t *battle_destroy(battle_t *battle)
{
    if (battle == NULL)
        return NULL;
    for (int i = 0; i < PLAYER_MAX; i++)
        free_for_each_player(battle, i);
    for (int i = 0; i < NOTE_TOTAL_SIZE; i++)
        if (battle->note_palettes[i] != NULL)
            free(battle->note_palettes[i]);
    if (battle->menu != NULL)
        menu_destroy(battle->menu);
    if (battle->note_tile != NULL)
        tile_destroy(battle->note_tile);
    free(battle);
    return NULL;
}

/*
** EPITECH PROJECT, 2022
** battle/notes/draw.c
** File description:
** Displays every note on screen
*/

#include "battles.h"
#include "const.h"
#include "struct.h"
#include "tiles.h"
#include <stdlib.h>

static void draw_single(battle_t *battle, int const player, int const id)
{
    note_t *note = battle->note[player][id];
    sfVector2f position = {0, 0};
    sfVector2f window_pos = battle->menu->window[player]->position;
    sfVector2i window_size = battle->menu->window[player]->size;
    sfVector2f offset = {window_pos.x + SONG_NOTE_OFFSET.x, 0};
    int rect_y = note->type % NOTE_TOTAL_SIZE;

    offset.y = window_pos.y + window_size.y - SONG_NOTE_OFFSET.y;
    position.x = note->type;
    position.y = (float)note->timing / SEC_TO_MICRO;
    position.y *= NOTE_SPEED;
    battle->note_tile->palette_pointed = &(battle->note_palettes[rect_y]);
    battle->note_tile->position.x = offset.x + position.x;
    battle->note_tile->position.y = offset.y - position.y;
    if (battle->note_tile->position.y < window_pos.y)
        return;
    battle->note_tile->texture_rect.y = note->type;
    tile_draw_from_sprite(battle->note_tile, battle->note_sprite, sfFalse);
}

static void draw_player(battle_t *battle, int const player)
{
    int length = 0;

    if (battle->note[player] == NULL)
        return;
    if (battle->menu == NULL || battle->menu->window == NULL)
        return;
    for (length = 0; battle->menu->window[length] != NULL; length++);
    if (player >= length)
        return;
    for (int i = 0; battle->note[player][i] != NULL; i++) {
        if (0 <= battle->note[player][i]->type)
            draw_single(battle, player, i);
    }
}

void battle_notes_draw(battle_t *battle)
{
    if (battle->note_sprite == NULL && battle->note_tile == NULL)
        return;
    battle->note_tile->position.x = POSITION_OUT_OF_SCREEN.x;
    battle->note_tile->position.x = POSITION_OUT_OF_SCREEN.y;
    tile_draw_from_sprite(battle->note_tile, battle->note_sprite, sfTrue);
    for (int i = 0; i < PLAYER_MAX; i++)
        draw_player(battle, i);
}

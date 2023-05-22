/*
** EPITECH PROJECT, 2022
** battle/create.c
** File description:
** Creates a battle struct
*/

#include "battles.h"
#include "filepaths.h"
#include "files.h"
#include "palettes.h"
#include "struct.h"
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

static tile_t *create_note_event(void)
{
    char *path = NULL;
    tile_t *tile = tile_create();

    if (tile == NULL)
        return NULL;
    path = path_form(FILE_MISC_NOTES_PNG, PATH_GRAPHICS);
    if (path == NULL)
        return tile;
    if (file_exists(path))
        tile->texture = sfTexture_createFromFile(path, NULL);
    free(path);
    return tile;
}

static void add_sounds(battle_t *battle, int const player, int const id)
{
    sfSoundBuffer *buffer = battle->note_buffer[player];

    battle->note_sound[player][id] = sfSound_create();
    if (battle->note_sound[player][id] == NULL || buffer == NULL)
        return;
    sfSound_setBuffer(battle->note_sound[player][id], buffer);
}

static sfSoundBuffer *add_sound_buffer(int const player)
{
    char *path = NULL;
    item_t *item = GAME.player[player].equipment[ITEM_TYPE_INSTRUMENT];
    sfSoundBuffer *buffer = NULL;

    if (item == NULL || item->sound_file == NULL)
        return NULL;
    path = path_form(item->sound_file, PATH_SFX);
    if (path == NULL)
        return NULL;
    if (file_exists(path))
        buffer = sfSoundBuffer_createFromFile(path);
    free(path);
    return buffer;
}

static void fill_values(battle_t *battle)
{
    for (int i = 0; i < PLAYER_MAX; i++) {
        battle->note_buffer[i] = add_sound_buffer(i);
        for (int j = 0; j < NOTE_TOTAL_SIZE; j++)
            add_sounds(battle, i, j);
        battle->note[i] = NULL;
    }
    for (int i = 0; i< STAT_TOTAL_SIZE; i++) {
        battle->stats_ally[i] = item_get_stats(i);
        battle->stats_enemy[i] = 0;
    }
    for (int i = 0; i < DAMAGE_TOTAL_SIZE; i++)
        battle->damage[i] = 0;
    for (int i = 0; i < NOTE_TOTAL_SIZE; i++)
        battle->note_palettes[i] = palette_get(SONG_NOTE_PALETTES[i]);
    battle->menu = NULL;
    battle->note_accuracy = 0;
    battle->note_sprite = sfSprite_create();
    battle->note_tile = create_note_event();
    battle->note_total = 0;
}

battle_t *battle_create(void)
{
    battle_t *battle = NULL;

    battle = malloc(sizeof(battle_t));
    if (battle == NULL)
        return NULL;
    fill_values(battle);
    return battle;
}

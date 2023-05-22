/*
** EPITECH PROJECT, 2022
** battles.h
** File description:
** Functions and structures requires for battles
*/

#pragma once
    #define TEMPO_DEFAULT 60

    #include "inputs.h"
    #include "items.h"
    #include "menus.h"
    #include "tiles.h"
    #include <SFML/Audio.h>
    #include <SFML/Graphics/Sprite.h>

enum notes_incidices {
    NOTE_LEFT,
    NOTE_MIDDLE,
    NOTE_RIGHT,
    NOTE_TOTAL_SIZE,
};

enum damages_indicies {
    DAMAGE_ACCURACY,
    DAMAGE_CRIT,
    DAMAGE_TOTAL_SIZE,
};

typedef struct note_s {
    float duration;
    float pitch;
    int tempo;
    int timing;
    int type;
} note_t;

typedef struct battle_s {
    sfColor *note_palettes[NOTE_TOTAL_SIZE];
    sfSound *note_sound[PLAYER_MAX][NOTE_TOTAL_SIZE];
    sfSoundBuffer *note_buffer[PLAYER_MAX];
    sfSprite *note_sprite;
    menu_t *menu;
    note_t **note[PLAYER_MAX];
    tile_t *note_tile;
    float damage[DAMAGE_TOTAL_SIZE];
    float stats_ally[STAT_TOTAL_SIZE];
    float stats_enemy[STAT_TOTAL_SIZE];
    double note_accuracy;
    int note_total;
} battle_t;

static const int BATTLE_RANDOM_TRIES = 100;
static const int BATTLE_SELECTION = 3;
static const int BATTLE_INPUTS[NOTE_TOTAL_SIZE] = {
    INPUT_NOTE_LEFT, INPUT_NOTE_MIDDLE, INPUT_NOTE_RIGHT,
};
static const char BATTLE_DEFAULT_INSTRUMENT[] = "note/iron_xylophone";

static const char ENEMY_SEPARATORS[] = "\t `";

static const char *SONG_NOTE_PALETTES[NOTE_TOTAL_SIZE] = {
    "misc/menu/p1",
    "misc/menu/p2",
    "misc/menu/p3",
};
static const sfVector2f SONG_NOTE_OFFSET = {1, 2};
static const char SONG_BAR_LINE[] = "|";
static const char SONG_TEMPO[] = "Tempo";
static const char SONG_SEPARATORS[] = "\t `";

//Returns NULL if a problem is encountered
battle_t *battle_create(void);
//Returns NULL
battle_t *battle_destroy(battle_t *battle);
//Returns 0 if a problem is encountered
//Otherwise, returns 1
int battle_enemy_get(battle_t *battle, char const *name);
sfBool battle_is_playing(battle_t const *battle);
void battle_song_add_note(note_t **notes, char * const *ary, int const tempo);
//Returns NULL if a problem is encountered
note_t **battle_song_get(battle_t *battle, char const *name);
void battle_notes_draw(battle_t *battle);
void battle_notes_press_correct(battle_t *btle, int const plyr, note_t *note);
void battle_notes_press_wrong(battle_t *battle, int const i, sfBool const m);
void battle_notes_update(battle_t *battle);
//Returns 0 if a problem is encountered
//Otherwise, returns 1
int battle_select(battle_t *battle);
void battle_select_update(battle_t *battle, menu_t *menu, char * const *slct);
//Returns 0 if a problem is encountered
//Otherwise, returns 1
int battle_start(char const *name);

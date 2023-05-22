/*
** EPITECH PROJECT, 2022
** structures.h
** File description:
** Generic structures
*/

#pragma once
    #include "const.h"
    #include "inputs.h"
    #include "items.h"
    #include "maps.h"
    #include "parallax.h"
    #include "sound.h"
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/System/Clock.h>
    #include <SFML/System/Vector2.h>

//Part of game_t
typedef struct player_s {
    inputs_t inputs;
    item_t *equipment[ITEM_TYPE_TOTAL_SIZE];
    sfColor skin_tone;
    sfVector2f position;
    int connected;
    int deltawalking;
    int direction;
    int skin_tone_id;
} player_t;

//Contains what needs to be accessible at (almost) ANY time
typedef struct game_s {
    music_t bgm;
    int delta;
    sfClock *deltaclock;
    char **inventory[ITEM_TYPE_TOTAL_SIZE];
    map_t *map;
    char *map_next;
    sfVector2f map_next_position;
    int mouse_click;
    sfVector2f mouse_position;
    parallax_t parallax;
    player_t player[PLAYER_MAX];
    int saved_variables[SAVED_VARIABLES];
    char **score;
    sfRenderWindow *window;
    sfBool window_focus;
    sfBool window_force_close;
    int window_fullscreen;
    sfVector2u window_size;
} game_t;

//Contains what needs to be accessible at (almost) ANY time
extern game_t GAME;

void game_free(void);
void game_initialise(void);
void window_create(int const fullscreen);
void window_destroy(void);
sfBool window_is_open(void);
sfVector2f window_get_size_ratio(void);
sfVector2u window_get_size(void);
//Returns 0 if there is no need to resize the window
//Otherwise, returns 1
int window_resize(void);

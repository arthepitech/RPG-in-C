/*
** EPITECH PROJECT, 2022
** items.h
** File description:
** Items and Inventory
*/

#pragma once
    #include "event.h"
    #include "tiles.h"
    #include <SFML/Config.h>

enum menu_tags_indices {
    MENU_TAG_CENTERED,
    MENU_TAG_CLOSE,
    MENU_TAG_FROMCENTER,
    MENU_TAG_MATCHALLYSTAT,
    MENU_TAG_MATCHBUT,
    MENU_TAG_MATCHENEMYSTAT,
    MENU_TAG_MATCHINSTRUMENT,
    MENU_TAG_MATCHKEY,
    MENU_TAG_MATCHOUTFIT,
    MENU_TAG_MATCHSOUNGCRIT,
    MENU_TAG_MATCHSOUNGDMG,
    MENU_TAG_MATCHSOUNGNAME,
    MENU_TAG_MATCHSTAT,
    MENU_TAG_PARALLAX,
    MENU_TAG_TOTAL_SIZE,
};

static const char *MENU_TAG_KEYS[MENU_TAG_TOTAL_SIZE] = {
    "centered",
    "close",
    "from_center",
    "match_ally_stat",
    "match_but",
    "match_enemy_stat",
    "match_instrument",
    "match_key",
    "match_outfit",
    "match_soung_crit",
    "match_soung_dmg",
    "match_soung_name",
    "match_stat",
    "parallax",
};

typedef struct menu_button_s {
    sfVector2f position;
    sfVector2f size;
    sfVector2u texture_size;
    script_t *script;
    tile_t *tile;
    char *text;
    int access;
    int tags[MENU_TAG_TOTAL_SIZE];
} menu_button_t;

typedef struct menu_window_s {
    sfBool tags[MENU_TAG_TOTAL_SIZE];
    sfVector2f position;
    sfVector2i size;
    tile_t *tile;
} menu_window_t;

typedef struct menu_s {
    sfBool closing;
    event_t **event;
    menu_button_t **button;
    menu_window_t **window;
    int selected[PLAYER_MAX];
} menu_t;

//Contains -1 at the end
static const int MENU_TAG_ARGS[] = {
    MENU_TAG_MATCHALLYSTAT,
    MENU_TAG_MATCHBUT,
    MENU_TAG_MATCHENEMYSTAT,
    MENU_TAG_MATCHKEY,
    MENU_TAG_MATCHSOUNGCRIT,
    MENU_TAG_MATCHSOUNGDMG,
    MENU_TAG_MATCHSOUNGNAME,
    MENU_TAG_MATCHSTAT,
    -1,
};

static const char FILE_DIALOGUE[] = "system/dialogue";

static const char MENU_SEPARATORS[] = " \t";
static const char MENU_BUTTON_KEY[] = "button";
static const char MENU_EVENT_KEY[] = "event";
static const char MENU_WINDOW_KEY[] = "window";

static const int MENU_BUTTON_SPACING_SIZE = 128;
static const int MENU_BUTTON_SPACING[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    3, 1, 3, 4, 3, 4, 4, 1, 2, 2, 3, 3, 1, 3, 1, 4,
    3, 2, 3, 3, 3, 3, 3, 4, 3, 3, 1, 1, 3, 3, 3, 3,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 5, 4, 4,
    4, 4, 4, 4, 3, 4, 4, 5, 3, 3, 4, 2, 4, 2, 3, 4,
    1, 3, 3, 3, 3, 4, 2, 3, 3, 1, 2, 3, 1, 5, 3, 4,
    3, 3, 3, 3, 2, 3, 3, 5, 3, 3, 3, 3, 1, 3, 4, 0,
};
static const char MENU_BUTTON_TEXTURE[] = "misc/text.png";
static const char MENU_WINDOW_TEXTURE[] = "misc/text_window.png";

//Returns NULL if a problem is encountered
menu_button_t *menu_button_create(void);
//Returns NULL if a problem is encountered
tile_t *menu_button_create_default_tile(void);
//Returns NULL
menu_button_t *menu_button_destroy(menu_button_t *menu_button);
void menu_button_draw(menu_button_t *menu_button);
//Returns NULL if a problem is encountered
menu_t *menu_create(void);
//Returns NULL
menu_t *menu_destroy(menu_t *menu);
void menu_draw(menu_t *menu);
//Returns 0 if a problem is encountered
//Otherwise, returns 1
int menu_open(char const *name);
void menu_open_loop(menu_t *menu);
//Returns NULL if a problem is encountered
menu_t *menu_get(char const *name);
void menu_get_button(menu_t *menu, char * const *ary);
void menu_get_event(menu_t *menu, char * const *ary);
void menu_get_window(menu_t *menu, char * const *ary);
void menu_update(menu_t *menu);
void menu_update_key(menu_t *menu, int const id);
void menu_update_movement(menu_t *menu, int const player);
void menu_update_name(menu_button_t *menu_button);
//Returns NULL if a problem is encountered
menu_window_t *menu_window_create(void);
//Returns NULL
menu_window_t *menu_window_destroy(menu_window_t *menu_window);
void menu_window_draw(menu_window_t *menu_window);

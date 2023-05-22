/*
** EPITECH PROJECT, 2022
** items.h
** File description:
** Items and Inventory
*/

#pragma once
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Texture.h>

enum item_types_indices {
    ITEM_TYPE_INSTRUMENT,
    ITEM_TYPE_OUTFIT,
    ITEM_TYPE_TOTAL_SIZE,
};

enum stats_indices {
    STAT_HEALTH,
    STAT_ATTACK,
    STAT_TOTAL_SIZE,
};

enum item_tags_indices {
    ITEM_TAG_NO_SKIN,
    ITEM_TAG_TOTAL_SIZE,
};

typedef struct item_s {
    sfColor *palette;
    sfTexture *texture;
    char *file;
    char *name;
    char *sound_file;
    float sound_volume;
    int cost;
    int tags[ITEM_TAG_TOTAL_SIZE];
    int type;
    int stats[STAT_TOTAL_SIZE];
} item_t;

static const int BASE_STATS[STAT_TOTAL_SIZE] = {1000, 100};
static const char *STAT_NAMES[STAT_TOTAL_SIZE] = {"HPs: ", "ATK: "};
static const char *STAT_SUFFIXES[STAT_TOTAL_SIZE] = {"", "%"};

static const int ITEM_DEFAULT_VOLUME = 100;
static const char ITEM_SEPARATORS[] = "` \t";
static const char *ITEM_TAG_KEYS[ITEM_TAG_TOTAL_SIZE] = {
    "no_skin",
};
static const char *ITEM_TYPE_KEYS[ITEM_TYPE_TOTAL_SIZE] = {
    "instrument",
    "outfit",
};

//Returns 1 if the music is added
//Otherwise, returns 0
int music_add(char const *name);
//Returns 1 if the item is added
//Otherwise, returns 0
int item_add(char const *name);
//Returns NULL if a problem is encountered
item_t *item_create(void);
//Returns NULL
item_t *item_destroy(item_t *item);
//Returns 1 if the item is equiped
//Otherwise, returns 0
int item_equip(char const *name, int const player);
void item_extract_texture(item_t *item, char const *arg);
//Returns NULL if a problem is encountered
item_t *item_get(char const *name);
//Returns 0 if the stat is unknown
int item_get_stats(int const stat);

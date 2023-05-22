/*
** EPITECH PROJECT, 2022
** maps.h
** File description:
** Final map composed of tilemaps and events
*/

#pragma once
    #include "event.h"
    #include "tiles.h"
    #define LAYER_PLAYER_LEVEL LAYER_WALLS

enum layers_indices {
    LAYER_GROUND,
    LAYER_GROUND_SECOND,
    LAYER_GROUND_OVERLAY,
    LAYER_TREES,
    LAYER_TREES_OVERLAY,
    LAYER_WALLS,
    LAYER_WALLS_OVERLAY,
    LAYER_ROOFS,
    LAYER_ROOFS_OVERLAY,
    LAYER_TOTAL_SIZE,
};

static const int LAYERS_UNDER_PLAYER[] = {
    LAYER_GROUND,
    LAYER_GROUND_SECOND,
    -1,
};

static const int LAYERS_WITH_PLAYER[] = {
    LAYER_GROUND_OVERLAY,
    LAYER_TREES,
    LAYER_WALLS,
    LAYER_WALLS_OVERLAY,
    -1,
};

static const int LAYERS_ABOVE_PLAYER[] = {
    LAYER_TREES_OVERLAY,
    LAYER_ROOFS,
    LAYER_ROOFS_OVERLAY,
    -1,
};

typedef struct map_s {
    event_t **event;
    tilemap_t *tilemap[LAYER_TOTAL_SIZE];
    char *bgm;
    char *file;
} map_t;

static const char MAP_SEPARATORS[] = "\t `";

int map_check_collisions(map_t const *map, float const x, float const y);
map_t *map_create(void);
map_t *map_destroy(map_t *map);
//View corresponds to the player's screen
//View = 0 corresponds to a global display
void map_draw(map_t *map, int const view);
//Returns the total of all values returned by event_execute( )
int map_execute(map_t *map, int const call_idx);
map_t *map_get(char const *name);
void map_update_event_layers(map_t *map, int const updates);

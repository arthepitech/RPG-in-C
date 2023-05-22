/*
** EPITECH PROJECT, 2022
** map/destroy.c
** File description:
** Destroys a map
*/

#include "maps.h"
#include <stdlib.h>

map_t *map_destroy(map_t *map)
{
    if (map == NULL)
        return NULL;
    if (map->bgm != NULL)
        free(map->bgm);
    if (map->file != NULL)
        free(map->file);
    if (map->event != NULL) {
        for (int i = 0; map->event[i] != NULL; i++)
            event_destroy(map->event[i]);
        free(map->event);
    }
    for (int i = 0; i < LAYER_TOTAL_SIZE; i++)
        if (map->tilemap[i] != NULL)
            tilemap_destroy(map->tilemap[i]);
    free(map);
}

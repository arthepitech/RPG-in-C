/*
** EPITECH PROJECT, 2022
** map/create.c
** File description:
** Creates a map
*/

#include "maps.h"
#include <stdlib.h>

map_t *map_create(void)
{
    map_t *map = NULL;

    map = malloc(sizeof(map_t));
    if (map == NULL)
        return NULL;
    map->event = NULL;
    map->bgm = NULL;
    map->file = NULL;
    for (int i = 0; i < LAYER_TOTAL_SIZE; i++)
        map->tilemap[i] = NULL;
    return map;
}

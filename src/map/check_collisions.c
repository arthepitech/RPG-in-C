/*
** EPITECH PROJECT, 2022
** map/check_collisions.c
** File description:
** Checks the collision at a point
*/

#include "hitboxes.h"
#include "maps.h"
#include <stdlib.h>

static int checking(map_t const *map,
float const x, float const y, int const layer)
{
    int returned = tilemap_check_collisions(map->tilemap[layer], x, y);

    if (returned != HITBOX_CHAR_NULL)
        return returned;
    if (layer <= 0)
        return HITBOX_CHAR_BLOCK;
    return checking(map, x, y, layer - 1);
}

int map_check_collisions(map_t const *map, float const x, float const y)
{
    if (map == NULL)
        return HITBOX_CHAR_BLOCK;
    return checking(map, x, y, LAYER_TOTAL_SIZE - 1);
}

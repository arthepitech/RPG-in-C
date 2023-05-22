/*
** EPITECH PROJECT, 2022
** tilemap/check_collisions.c
** File description:
** Checks the collision at a point
*/

#include "hitboxes.h"
#include "tiles.h"
#include <stdlib.h>

static int check_tile(tile_t const *tile, float const x, float const y)
{
    int pixel_x = ((float)(x - (int)x) * 10 * TILE) / 10;
    int pixel_y = ((float)(y - (int)y) * 10 * TILE) / 10;

    if (tile == NULL || tile->hitbox == NULL)
        return HITBOX_CHAR_NULL;
    return tile->hitbox->ary[pixel_y % TILE][pixel_x % TILE];
}

int tilemap_check_collisions(tilemap_t const *tilemap,
float const x, float const y)
{
    if (tilemap == NULL)
        return HITBOX_CHAR_NULL;
    if (tilemap->size.x <= (int)x || tilemap->size.y <= (int)y)
        return HITBOX_CHAR_NULL;
    if (x < 0 || y < 0)
        return HITBOX_CHAR_NULL;
    return check_tile(tilemap->tile[(int)x][(int)y], x, y);
}

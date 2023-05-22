/*
** EPITECH PROJECT, 2022
** tile/create.c
** File description:
** Creates a tile
*/

#include "tiles.h"
#include <stdlib.h>

static void set_default_values(tile_t *tile)
{
    tile->palette_pointed = NULL;
    tile->palette = NULL;
    tile->position.x = 0;
    tile->position.y = 0;
    tile->texture_pointed = NULL;
    tile->texture_rect.x = 0;
    tile->texture_rect.y = 0;
    tile->texture = NULL;
    tile->hitbox = NULL;
}

tile_t *tile_create(void)
{
    tile_t *tile = NULL;

    tile = malloc(sizeof(tile_t));
    if (tile == NULL)
        return NULL;
    set_default_values(tile);
    return tile;
}

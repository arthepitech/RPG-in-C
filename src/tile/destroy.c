/*
** EPITECH PROJECT, 2022
** tile/destroy.c
** File description:
** Destroys a tile
*/

#include "palettes.h"
#include "tiles.h"
#include <stdlib.h>
#include <SFML/Graphics/Texture.h>

static void destroy_none_pointers(tile_t *tile)
{
    if (tile == NULL)
        return;
    if (tile->palette != NULL)
        palette_destroy(tile->palette);
    if (tile->texture != NULL)
        sfTexture_destroy(tile->texture);
    if (tile->hitbox != NULL)
        hitbox_destroy(tile->hitbox);
}

tile_t *tile_destroy(tile_t *tile)
{
    if (tile == NULL)
        return NULL;
    destroy_none_pointers(tile);
    free(tile);
    return NULL;
}

tile_t *tile_destroy_with_pointers(tile_t *tile)
{
    if (tile == NULL)
        return NULL;
    destroy_none_pointers(tile);
    if (tile->palette_pointed != NULL) {
        if (*(tile->palette_pointed) != NULL)
            palette_destroy(*(tile->palette_pointed));
        free(tile->palette_pointed);
    }
    if (tile->texture_pointed != NULL) {
        if (*(tile->texture_pointed) != NULL)
            sfTexture_destroy(*(tile->texture_pointed));
        free(tile->texture_pointed);
    }
    return NULL;
}

/*
** EPITECH PROJECT, 2022
** tilemap/destroy.c
** File description:
** Destroys a tilemap
*/

#include "tiles.h"
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>

static int free_tiles(tilemap_t *tilemap)
{
    if (tilemap->tile == NULL)
        return 0;
    for (int i = 0; tilemap->tile[i] != NULL; i++) {
        for (int j = 0; tilemap->tile[i][j] != NULL; j++)
            tile_destroy(tilemap->tile[i][j]);
        free(tilemap->tile[i]);
    }
    free(tilemap->tile);
    return 0;
}

tilemap_t *tilemap_destroy(tilemap_t *tilemap)
{
    if (tilemap == NULL)
        return NULL;
    if (tilemap->texture != NULL)
        sfTexture_destroy(tilemap->texture);
    free_tiles(tilemap);
    free(tilemap);
    return NULL;
}

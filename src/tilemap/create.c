/*
** EPITECH PROJECT, 2022
** tilemap/create.c
** File description:
** Creates a tilemap
*/

#include "tiles.h"
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

static int fill_cases(tile_t **tile, int x, int y)
{
    for (int i = 0; i < y; i++)
        tile[i] == NULL;
    return 1;
}

static int fill_lines(tilemap_t *tilemap, int x, int y)
{
    for (int i = 0; i < x; i++) {
        tilemap->tile[i] = malloc(sizeof(tile_t *) * (y + 1));
        if (tilemap->tile[i] == NULL)
            return free_tiles(tilemap);
        for (int j = 0; j < (y + 1); j++)
            tilemap->tile[i][j] = NULL;
        if (!fill_cases(tilemap->tile[i], x, y))
            return free_tiles(tilemap);
    }
}

static int fill_tiles(tilemap_t *tilemap, int x, int y)
{
    tilemap->tile = malloc(sizeof(tile_t **) * (x + 1));
    if (tilemap->tile == NULL)
        return 0;
    for (int i = 0; i < (x + 1); i++)
        tilemap->tile[i] = NULL;
    if (!fill_lines(tilemap, x, y))
        return 0;
    return 1;
}

tilemap_t *tilemap_create(int x, int y)
{
    tilemap_t *tilemap = NULL;

    tilemap = malloc(sizeof(tilemap_t));
    if (tilemap == NULL)
        return NULL;
    tilemap->texture = NULL;
    tilemap->size.x = x;
    tilemap->size.y = y;
    tilemap->tile = NULL;
    fill_tiles(tilemap, x, y);
    return tilemap;
}

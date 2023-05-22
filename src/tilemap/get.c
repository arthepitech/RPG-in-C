/*
** EPITECH PROJECT, 2022
** tilemap/get.c
** File description:
** Search a tilemap in files
*/

#include "filepaths.h"
#include "files.h"
#include "my.h"
#include "palettes.h"
#include "tiles.h"
#include <stdlib.h>
#include <SFML/Graphics/Texture.h>

static int check_size(char * const *ary, sfVector2i *size)
{
    int i = 0;
    int returned = 0;

    if (ary == NULL || ary[i] == NULL)
        return 0;
    for (i = 0; ary[i][0] != 'M' && LEN(ary[i]) != 3 && ary[i] != NULL; i++);
    i++;
    returned = i;
    if (size == NULL)
        return returned;
    for (; ary[i] != NULL; i++) {
        if (ary[i][0] != '\0') {
            size->x = MIN(size->x, LEN(ary[i]));
            size->y += 1;
        }
    }
    return returned;
}

static tile_t *new_tile(char * const *ary, sfVector2i coor, int const start)
{
    int line = -1;
    char icon = '\0';
    tile_t *tile = NULL;

    if (coor.x < LEN(ary[coor.y + start]))
        icon = ary[coor.y + start][coor.x];
    tile = tile_create();
    if (tile == NULL)
        return NULL;
    for (int i = 1; i < start && ary[i] != NULL; i++)
        if (ary[i][0] == TILEMAP_ENTRIES[0] && ary[i][1] == icon)
            line = i;
    if (line < 0)
        return tile;
    tilemap_extract_tile(tile, ary[line]);
    return tile;
}

static void fill_tiles(tilemap_t *tilemap, char * const *ary)
{
    int start = check_size(ary, NULL);
    sfVector2i coor = {0, 0};

    for (int x = 0; x < tilemap->size.x; x++) {
        for (int y = 0; y < tilemap->size.y; y++) {
            coor.x = x;
            coor.y = y;
            tilemap->tile[x][y] = new_tile(ary, coor, start);
        }
    }
}

static tilemap_t *complete_tilemap(char * const *ary)
{
    sfVector2i size = {0, 0};
    int starting = check_size(ary, &size);
    tilemap_t *tilemap = NULL;
    char *path = NULL;

    if (ary == NULL || ary[0] == NULL)
        return NULL;
    tilemap = tilemap_create(size.x, size.y);
    if (tilemap == NULL)
        return NULL;
    path = path_form(ary[0], PATH_GRAPHICS);
    if (file_exists(path))
        tilemap->texture = sfTexture_createFromFile(path, NULL);
    if (path != NULL)
        free(path);
    fill_tiles(tilemap, ary);
    return tilemap;
}

tilemap_t *tilemap_get(char const *name)
{
    char **ary = NULL;
    tilemap_t *tilemap = NULL;

    ary = path_form_and_convert(name, PATH_TILEMAPS);
    if (ary == NULL)
        return NULL;
    tilemap = complete_tilemap(ary);
    my_free_char_2d(ary);
    if (tilemap == NULL)
        return NULL;
    return tilemap;
}

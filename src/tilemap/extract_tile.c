/*
** EPITECH PROJECT, 2022
** tilemap/extract_tile.c
** File description:
** Required for tilemap/get.c
*/

#include "my.h"
#include "palettes.h"
#include "tiles.h"
#include <stdlib.h>

static void extract_informations(tile_t *tile, char * const *ary)
{
    int length = 0;

    for (length = 0; ary[length] != NULL; length++);
    if (length > 1)
        tile->palette = palette_get(ary[1]);
    if (length > 2)
        tile->texture_rect.x = my_str_to_int(ary[2]);
    if (length > 3)
        tile->texture_rect.y = my_str_to_int(ary[3]);
    if (length > 4)
        tile->hitbox = hitbox_get(ary[4]);
}

void tilemap_extract_tile(tile_t *tile, char const *str)
{
    char **ary = NULL;

    if (tile == NULL || str == NULL)
        return;
    ary = my_str_to_array(str, TILEMAP_SEPARATORS);
    if (ary == NULL)
        return;
    extract_informations(tile, ary);
    my_free_char_2d(ary);
}

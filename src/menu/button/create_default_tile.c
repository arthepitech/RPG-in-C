/*
** EPITECH PROJECT, 2022
** menu/button/create_default_tile.c
** File description:
** Creates a tile for a button
*/

#include "filepaths.h"
#include "files.h"
#include "menus.h"
#include <stdlib.h>
#include <SFML/Graphics/Texture.h>

tile_t *menu_button_create_default_tile(void)
{
    tile_t *tile = tile_create();
    char *path = NULL;

    if (tile == NULL)
        return NULL;
    path = path_form(MENU_BUTTON_TEXTURE, PATH_GRAPHICS);
    if (path == NULL)
        return tile;
    if (file_exists(path))
        tile->texture = sfTexture_createFromFile(path, NULL);
    free(path);
    return tile;
}

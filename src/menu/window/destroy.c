/*
** EPITECH PROJECT, 2022
** menu/window/destroy.c
** File description:
** Destroys a window from a menu
*/

#include "menus.h"
#include "tiles.h"
#include <stdlib.h>

menu_window_t *menu_window_destroy(menu_window_t *menu_window)
{
    if (menu_window == NULL)
        return NULL;
    if (menu_window->tile != NULL)
        tile_destroy(menu_window->tile);
    free(menu_window);
    return NULL;
}

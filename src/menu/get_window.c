/*
** EPITECH PROJECT, 2022
** menu/get_window.c
** File description:
** Used by menu_get.c for managing windows
*/

#include "const.h"
#include "filepaths.h"
#include "files.h"
#include "menus.h"
#include "my.h"
#include "palettes.h"
#include "tiles.h"
#include <stdlib.h>
#include <SFML/Graphics/Texture.h>

static tile_t *create_default_tile(void)
{
    tile_t *tile = tile_create();
    char *path = NULL;

    if (tile == NULL)
        return NULL;
    path = path_form(MENU_WINDOW_TEXTURE, PATH_GRAPHICS);
    if (path == NULL)
        return tile;
    if (file_exists(path))
        tile->texture = sfTexture_createFromFile(path, NULL);
    free(path);
    return tile;
}

static void check_tags(menu_window_t *menu_window, char const *str)
{
    for (int i = 0; i < MENU_TAG_TOTAL_SIZE; i++) {
        if (my_strcmp(str, MENU_TAG_KEYS[i])) {
            menu_window->tags[i] = sfTrue;
        }
    }
}

static void extract_args(menu_window_t *menu_window, char * const *ary)
{
    int length = 0;

    for (length = 0; ary[length] != NULL; length++);
    if (length >= 2)
        menu_window->tile->palette = palette_get(ary[1]);
    if (length >= 3)
        menu_window->size.x = my_str_to_int(ary[2]);
    if (length >= 4)
        menu_window->size.y = my_str_to_int(ary[3]);
    if (length >= 5)
        menu_window->position.x = my_str_to_double(ary[4]);
    if (length >= 6)
        menu_window->position.y = my_str_to_double(ary[5]);
    for (int i = 6; i < length; i++)
        check_tags(menu_window, ary[i]);
}

static menu_window_t *extract_window(char * const *ary)
{
    menu_window_t *menu_window = menu_window_create();

    if (menu_window == NULL)
        return NULL;
    menu_window->tile = create_default_tile();
    if (menu_window->tile == NULL)
        return NULL;
    extract_args(menu_window, ary);
    if (menu_window->tags[MENU_TAG_FROMCENTER]) {
        menu_window->position.x += (SCREEN_RESOLUTION.x / TILE) / 2;
        menu_window->position.y += (SCREEN_RESOLUTION.y / TILE) / 2;
    }
    if (menu_window->tags[MENU_TAG_CENTERED]) {
        menu_window->position.x -= menu_window->size.x / 2;
        menu_window->position.y -= menu_window->size.y / 2;
    }
    return menu_window;
}

void menu_get_window(menu_t *menu, char * const *ary)
{
    menu_window_t *menu_window = NULL;
    int id = 0;

    if (menu == NULL || menu->window == NULL || ary == NULL || ary[0] == NULL)
        return;
    menu_window = extract_window(ary);
    if (menu_window == NULL)
        return;
    for (id = 0; menu->window[id] != NULL; id++);
    menu->window[id] = menu_window;
}

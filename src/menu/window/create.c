/*
** EPITECH PROJECT, 2022
** menu/window/create.c
** File description:
** Creates a window for a menu
*/

#include "menus.h"
#include <stdlib.h>

menu_window_t *menu_window_create(void)
{
    menu_window_t *menu_window = NULL;

    menu_window = malloc(sizeof(menu_window_t));
    if (menu_window == NULL)
        return NULL;
    menu_window->position.x = 0;
    menu_window->position.y = 0;
    menu_window->size.x = 0;
    menu_window->size.y = 0;
    menu_window->tile = NULL;
    for (int i = 0; i < MENU_TAG_TOTAL_SIZE; i++)
        menu_window->tags[i] = sfFalse;
    return menu_window;
}

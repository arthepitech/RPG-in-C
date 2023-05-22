/*
** EPITECH PROJECT, 2022
** menu/create.c
** File description:
** Creates a menu
*/

#include "menus.h"
#include <stdlib.h>

menu_t *menu_create(void)
{
    menu_t *menu = NULL;

    menu = malloc(sizeof(menu_t));
    if (menu == NULL)
        return NULL;
    for (int i = 0; i < PLAYER_MAX; i++)
        menu->selected[i] = -1;
    menu->closing = sfFalse;
    menu->button = NULL;
    menu->event = NULL;
    menu->window = NULL;
    return menu;
}

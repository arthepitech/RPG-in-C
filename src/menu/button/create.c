/*
** EPITECH PROJECT, 2022
** menu/button/create.c
** File description:
** Creates a button for a menu
*/

#include "menus.h"
#include <stdlib.h>

static void default_values_null(menu_button_t *menu_button)
{
    menu_button->tile = NULL;
    menu_button->text = NULL;
    menu_button->script = NULL;
}

menu_button_t *menu_button_create(void)
{
    menu_button_t *menu_button = NULL;

    menu_button = malloc(sizeof(menu_button_t));
    if (menu_button == NULL)
        return NULL;
    default_values_null(menu_button);
    menu_button->access = -1;
    menu_button->position.x = 0;
    menu_button->position.y = 0;
    menu_button->size.x = 0;
    menu_button->size.y = 0;
    menu_button->texture_size.x = -1;
    menu_button->texture_size.y = -1;
    for (int i = 0; i < MENU_TAG_TOTAL_SIZE; i++)
        menu_button->tags[i] = sfFalse;
    return menu_button;
}

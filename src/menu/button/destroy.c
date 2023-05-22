/*
** EPITECH PROJECT, 2022
** menu/button/destroy.c
** File description:
** Destroys a button from a menu
*/

#include "script.h"
#include "menus.h"
#include <stdlib.h>

menu_button_t *menu_button_destroy(menu_button_t *menu_button)
{
    if (menu_button == NULL)
        return NULL;
    if (menu_button->script != NULL)
        script_destroy(menu_button->script);
    if (menu_button->tile != NULL)
        tile_destroy_with_pointers(menu_button->tile);
    if (menu_button->text != NULL)
        free(menu_button->text);
    free(menu_button);
    return NULL;
}

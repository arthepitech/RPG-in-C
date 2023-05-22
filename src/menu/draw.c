/*
** EPITECH PROJECT, 2022
** menu/draw.c
** File description:
** Displays an entire menu on screen
*/

#include "menus.h"
#include <stdlib.h>

void menu_draw(menu_t *menu)
{
    if (menu == NULL)
        return;
    if (menu->window != NULL)
        for (int i = 0; menu->window[i] != NULL; i++)
            menu_window_draw(menu->window[i]);
    if (menu->event != NULL)
        for (int i = 0; menu->event[i] != NULL; i++)
            event_draw(menu->event[i]);
    if (menu->button != NULL)
        for (int i = 0; menu->button[i] != NULL; i++)
            menu_button_draw(menu->button[i]);
}

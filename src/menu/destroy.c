/*
** EPITECH PROJECT, 2022
** menu/destroy.c
** File description:
** Destroys a menu
*/

#include "event.h"
#include "menus.h"
#include <stdlib.h>

static void free_buttons(menu_t *menu)
{
    if (menu->button == NULL)
        return;
    for (int i = 0; menu->button[i] != NULL; i++)
        menu_button_destroy(menu->button[i]);
    free(menu->button);
}

static void free_events(menu_t *menu)
{
    if (menu->event == NULL)
        return;
    for (int i = 0; menu->event[i] != NULL; i++)
        event_destroy(menu->event[i]);
    free(menu->event);
}

static void free_windows(menu_t *menu)
{
    if (menu->window == NULL)
        return;
    for (int i = 0; menu->window[i] != NULL; i++)
        menu_window_destroy(menu->window[i]);
    free(menu->window);
}

menu_t *menu_destroy(menu_t *menu)
{
    if (menu == NULL)
        return NULL;
    free_buttons(menu);
    free_events(menu);
    free_windows(menu);
    free(menu);
    return NULL;
}

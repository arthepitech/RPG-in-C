/*
** EPITECH PROJECT, 2022
** menu/get_event.c
** File description:
** Used by menu_get.c for managing events
*/

#include "event.h"
#include "menus.h"
#include "my.h"
#include <stdlib.h>

static event_t *extract_event(menu_t *menu, char * const *ary)
{
    int length = 0;
    event_t *event = NULL;

    for (length = 0; ary[length] != NULL; length++);
    if (length >= 2)
        event = event_get(ary[1]);
    if (event == NULL)
        return NULL;
    if (length >= 3)
        event->position.x = my_str_to_double(ary[2]);
    if (length >= 4)
        event->position.y = my_str_to_double(ary[3]);
    for (int i = 4; i < length && (i - 4) < EVENT_VAR_SIZE; i++)
        event->variable[i - 4] = my_str_to_double(ary[i]);
    return event;
}

static void align_with_window(menu_t const *menu, event_t *event)
{
    int id = 0;

    if (menu == NULL || menu->window == NULL)
        return;
    for (id = 0; menu->window[id] != NULL; id++);
    if (id <= 0)
        return;
    event->position.x += menu->window[id - 1]->position.x;
    event->position.y += menu->window[id - 1]->position.y;
}

void menu_get_event(menu_t *menu, char * const *ary)
{
    event_t *event = NULL;
    int id = 0;

    if (menu == NULL || menu->event == NULL || ary == NULL || ary[0] == NULL)
        return;
    event = extract_event(menu, ary);
    if (event == NULL)
        return;
    align_with_window(menu, event);
    for (id = 0; menu->event[id] != NULL; id++);
    menu->event[id] = event;
    event_execute(event, CALL_ONLOAD);
}

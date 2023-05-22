/*
** EPITECH PROJECT, 2022
** map/update_event_layers.c
** File description:
** Updates events' positions according to other events
*/

#include "maps.h"
#include <stdlib.h>

static void swap_events(event_t **event1, event_t **event2)
{
    event_t *event = *event1;

    *event1 = *event2;
    *event2 = event;
}

static int is_swapping_required(event_t const *bottom, event_t const *top)
{
    if (bottom == NULL || top == NULL)
        return 0;
    if (bottom->layer > top->layer)
        return 1;
    if (bottom->layer != top->layer)
        return 0;
    if (bottom->position.y > top->position.y)
        return 1;
    return 0;
}

static int try_to_swap(map_t *map)
{
    if (map == NULL)
        return 0;
    for (int i = 0; map->event[i] != NULL; i++) {
        if (is_swapping_required(map->event[i], map->event[i + 1])) {
            swap_events(&map->event[i], &map->event[i + 1]);
            return 1;
        }
    }
    return 0;
}

void map_update_event_layers(map_t *map, int const updates)
{
    int has_swapped = 0;

    if (map == NULL || map->event == NULL || updates <= 0)
        return;
    has_swapped = try_to_swap(map);
    if (!has_swapped)
        return;
    map_update_event_layers(map, updates - 1);
}

/*
** EPITECH PROJECT, 2022
** map/draw.c
** File description:
** Draws a map with tilemaps and events
*/

#include "maps.h"
#include <stdlib.h>

static void draw_tilemap_line(map_t *map, int const *layers, int const line)
{
    if (layers == NULL)
        return;
    for (int i = 0; layers[i] >= 0; i++)
        if (map->tilemap[layers[i]] != NULL)
            tilemap_draw_line(map->tilemap[layers[i]], line);
}

static void draw_events_line(map_t *map, int const line, int const view)
{
    int event_view = 0;

    if (map == NULL || map->event == NULL)
        return;
    for (int i = 0; map->event[i] != NULL; i++) {
        event_view = map->event[i]->view;
        if (event_view == view)
            event_view = 0;
        if (line < 0 && map->event[i]->layer == 0)
            event_view = -1;
        if (line >= 0 && map->event[i]->layer != 0)
            event_view = -1;
        if (line >= 0 && (int)(map->event[i]->position.y) != line)
            event_view = -1;
        if (event_view == 0)
            event_draw(map->event[i]);
    }
}

static void draw_tilemaps_with_events(map_t *map, int const *layers,
int const view)
{
    int i = 0;

    for (i = 0; map->tilemap[0] != NULL && i < map->tilemap[0]->size.y; i++) {
        draw_tilemap_line(map, layers, i);
        draw_events_line(map, i, view);
    }
}

static void draw_tilemaps(map_t *map, int const *layers)
{
    if (layers == NULL)
        return;
    for (int i = 0; layers[i] >= 0; i++)
        if (map->tilemap[layers[i]] != NULL)
            tilemap_draw(map->tilemap[layers[i]]);
}

void map_draw(map_t *map, int const view)
{
    int event_view = 0;

    if (map == NULL)
        return;
    map_update_event_layers(map, 1);
    draw_tilemaps(map, LAYERS_UNDER_PLAYER);
    draw_tilemaps_with_events(map, LAYERS_WITH_PLAYER, view);
    draw_tilemaps(map, LAYERS_ABOVE_PLAYER);
    draw_events_line(map, -1, view);
}

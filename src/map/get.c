/*
** EPITECH PROJECT, 2022
** map/get.c
** File description:
** Search a map in files
*/

#include "filepaths.h"
#include "maps.h"
#include "my.h"
#include "sound.h"
#include <stdlib.h>

static event_t *write_event(char const *str)
{
    event_t *event = NULL;
    char **ary = NULL;
    int length = 0;

    ary = my_str_to_array(str, MAP_SEPARATORS);
    if (ary == NULL)
        return NULL;
    for (length = 0; ary[length] != NULL; length++);
    if (length >= 1)
        event = event_get(ary[0]);
    if (event == NULL)
        return NULL;
    if (length >= 3) {
        event->position.x = my_str_to_double(ary[1]);
        event->position.y = my_str_to_double(ary[2]);
    }
    for (int i = 3; i < length && i - 3 < EVENT_VAR_SIZE; i++)
        event->variable[i - 3] = my_str_to_double(ary[i]);
    return event;
}

static void map_convert(map_t *map, char * const *ary)
{
    int event_count = 0;
    int length = 0;
    int line_id = LAYER_TOTAL_SIZE + 1;

    for (length = 0; ary[length] != NULL; length++);
    for (int i = 0; ary[i] != NULL && i < LAYER_TOTAL_SIZE; i++)
        map->tilemap[i] = tilemap_get(ary[i]);
    if (length >= LAYER_TOTAL_SIZE + 1)
        map->bgm = DUP(ary[LAYER_TOTAL_SIZE]);
    event_count = length - (LAYER_TOTAL_SIZE + 1);
    map->event = malloc(sizeof(event_t *) * (event_count + 1));
    if (map->event == NULL)
        return;
    for (int i = 0; i < (event_count + 1); i++)
        map->event[i] = NULL;
    for (int i = 0; i < event_count && line_id < length; i++) {
        map->event[i] = write_event(ary[line_id]);
        if (map->event[i] != NULL)
            line_id += 1;
    }
}

map_t *map_get(char const *name)
{
    char **ary = NULL;
    map_t *map = map_create();

    if (map == NULL)
        return NULL;
    ary = path_form_and_convert(name, PATH_MAPS);
    if (ary == NULL) {
        map_destroy(map);
        return NULL;
    }
    map->file = DUP(name);
    map_convert(map, ary);
    if (map->bgm != NULL)
        bgm_play(map->bgm);
    map_execute(map, CALL_ONLOAD);
    return map;
}

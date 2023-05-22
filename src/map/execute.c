/*
** EPITECH PROJECT, 2022
** map/execute.c
** File description:
** Search a map in files
*/

#include "maps.h"
#include <stdlib.h>

int map_execute(map_t *map, int const call_idx)
{
    int returned = 0;

    if (map == NULL || map->event == NULL)
        return 0;
    if (call_idx < 0 || CALL_TOTAL_SIZE <= call_idx)
        return 0;
    for (int i = 0; map->event[i] != NULL; i++)
        returned += event_execute(map->event[i], call_idx);
    return returned;
}

/*
** EPITECH PROJECT, 2022
** tick/update_calls.c
** File description:
** Check for >player_contact
*/

#include "event.h"
#include "struct.h"
#include <stddef.h>

int tick_events_update_calls(void)
{
    if (GAME.map == NULL)
        return 0;
    if (GAME.map->event == NULL || GAME.map->event[0] == NULL)
        return 0;
    for (int i = 0; GAME.map->event[i] != NULL; i++)
        event_check_player_contact(GAME.map->event[i]);
    return 1;
}

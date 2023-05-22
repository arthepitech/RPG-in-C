/*
** EPITECH PROJECT, 2022
** command/execute/place_event.c
** File description:
** Place a new event
*/

#include "const.h"
#include "event.h"
#include "my.h"
#include "script.h"
#include "struct.h"
#include <stdlib.h>

static void add_event(event_t *event)
{
    int length = 0;
    event_t **new_events = NULL;

    for (length = 0; GAME.map->event[length] != NULL; length++);
    new_events = malloc(sizeof(event_t *) * (length + 2));
    if (new_events == NULL)
        return;
    for (int i = 0; i < length; i++)
        new_events[i] = GAME.map->event[i];
    for (int i = length; i < (length + 2); i++)
        new_events[i] = NULL;
    new_events[length] = event;
    free(GAME.map->event);
    GAME.map->event = new_events;
    event_execute(event, CALL_ONLOAD);
}

static int place_event(command_t command, event_t *event2)
{
    event_t *event = event_get(command.ary[1]);

    if (event == NULL)
        return 0;
    if (command.length > 2)
        event->position.x = my_str_to_double(command.ary[2]);
    if (command.length > 3)
        event->position.y = my_str_to_double(command.ary[3]);
    for (int i = 4; i < command.length && i < EVENT_VAR_SIZE; i++)
        event->variable[i - 4] = command_get_argument(command.ary[4], event2);
    add_event(event);
    return 1;
}

int command_execute_place_event(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 2)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (GAME.map == NULL || GAME.map->event == NULL)
        return 0;
    return place_event(command, event);
}

/*
** EPITECH PROJECT, 2022
** event/check_player_contact.c
** File description:
** Adds a script to an already existing event
*/

#include "event.h"
#include "my.h"
#include "struct.h"
#include <stdlib.h>

static int check_player_tile(event_t *event, int const player)
{
    float var_player = 0;
    sfVector2f player_center = GAME.player[player].position;

    if (!GAME.player[player].connected)
        return 0;
    player_center.x += (float)1 / 2;
    player_center.y += 1;
    if ((int)player_center.x != (int)event->position.x)
        return 0;
    if ((int)player_center.y != (int)event->position.y)
        return 0;
    var_player = event->variable[EVENT_VAR_PLAYER];
    event->variable[EVENT_VAR_PLAYER] = player + 1;
    event_execute(event, CALL_PLAYERTILE);
    event->variable[EVENT_VAR_PLAYER] = var_player;
    return 1;
}

static int check_player(event_t *event, int const player)
{
    float var_player = 0;
    sfVector2f range = EVENT_CONTACT_RANGE;
    sfVector2f distance = {0, 0};

    if (!GAME.player[player].connected)
        return 0;
    distance.x = GAME.player[player].position.x - event->position.x;
    distance.y = GAME.player[player].position.y - event->position.y;
    if (ABS(distance.x) > range.x || ABS(distance.y) > range.y)
        return 0;
    var_player = event->variable[EVENT_VAR_PLAYER];
    event->variable[EVENT_VAR_PLAYER] = player + 1;
    event_execute(event, CALL_PLAYERTILE);
    event_execute(event, CALL_PLAYERCONTACT);
    if (GAME.player[player].inputs.press[INPUT_INTERACT] == 1)
        event_execute(event, CALL_PLAYERINTERACTION);
    event->variable[EVENT_VAR_PLAYER] = var_player;
    return 1;
}

int event_check_player_contact(event_t *event)
{
    int returned = 0;

    if (event == NULL)
        return 0;
    for (int i = 0; i < PLAYER_MAX; i++) {
        returned += check_player(event, i);
        returned += check_player_tile(event, i);
    }
    if (returned <= 0)
        return 0;
    return 1;
}

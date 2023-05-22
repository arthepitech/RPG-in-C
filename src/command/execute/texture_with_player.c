/*
** EPITECH PROJECT, 2022
** command/execute/texture_with_player.c
** File description:
** Put the right animation frame to a player event
*/

#include "calls.h"
#include "const.h"
#include "event.h"
#include "items.h"
#include "my.h"
#include "palettes.h"
#include "script.h"
#include "struct.h"
#include <stdlib.h>

static void palette_and_sprite(event_t *event, int const player)
{
    sfTexture **texture = NULL;
    sfColor **palette = NULL;
    item_t *item = GAME.player[player].equipment[ITEM_TYPE_OUTFIT];

    if (item != NULL) {
        texture = &item->texture;
        palette = &item->palette;
    }
    event->tile->texture_pointed = texture;
    event->tile->palette_pointed = palette;
    if (event->tile->palette != NULL)
        event->tile->palette[COLOR_LAYER_SKIN] = GAME.player[player].skin_tone;
    if (item == NULL || item->palette == NULL)
        return;
    if (!item->tags[ITEM_TAG_NO_SKIN])
        item->palette[COLOR_LAYER_SKIN] = GAME.player[player].skin_tone;
}

static int animate(event_t *event, int player)
{
    if (player > 0)
        player -= 1;
    if (player < 0 || PLAYER_MAX <= player)
        return 0;
    palette_and_sprite(event, player);
    return 1;
}

int command_execute_texture_with_player(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 2)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 2)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    if (event == NULL)
        return 0;
    return animate(event, command_get_argument(command.ary[1], event));
}

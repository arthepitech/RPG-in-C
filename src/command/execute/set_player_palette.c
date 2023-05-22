/*
** EPITECH PROJECT, 2022
** command/execute/set_palette_player.c
** File description:
** Move the event to the player's position
*/

#include "const.h"
#include "event.h"
#include "my.h"
#include "palettes.h"
#include "script.h"
#include <stdlib.h>

static int set_palette(event_t *event, int player)
{
    sfColor *palette = NULL;

    if (player < 0) {
        palette = palette_get(PLAYER_DEFAULT_PALETTE);
    } else {
        if (player > 0)
            player -= 1;
        player %= PLAYER_MAX;
        palette = palette_get(PLAYER_PALETTES[player % PLAYER_MAX]);
    }
    if (event->tile->palette != NULL)
        palette_destroy(event->tile->palette);
    event->tile->palette = palette;
    return 1;
}

int command_execute_set_palette_player(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 2)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 2)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    if (event == NULL)
        return 0;
    return set_palette(event, command_get_argument(command.ary[1], event));
}

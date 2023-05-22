/*
** EPITECH PROJECT, 2022
** command/execute/change_player_skin_tone.c
** File description:
** Move the event to the player's position
*/

#include "const.h"
#include "event.h"
#include "filepaths.h"
#include "my.h"
#include "palettes.h"
#include "struct.h"
#include <stdlib.h>
#include <SFML/Graphics/Color.h>

static void set_color(int const player, char * const *ary)
{
    sfColor tone = color_get(ary[GAME.player[player].skin_tone_id]);

    GAME.player[player].skin_tone.r = tone.r;
    GAME.player[player].skin_tone.g = tone.g;
    GAME.player[player].skin_tone.b = tone.b;
}

static void prepare_change_skin(int const player)
{
    int *skin_tone_id = &GAME.player[player].skin_tone_id;
    int length = 0;
    char **ary = NULL;

    ary = path_form_and_convert(FILE_SKIN_TONES_TXT, PATH_MISC);
    if (ary == NULL)
        return;
    if (ary[0] == NULL) {
        my_free_char_2d(ary);
        return;
    }
    for (length = 0; ary[length] != NULL; length++);
    *skin_tone_id = (*skin_tone_id + 1) % length;
    set_color(player, ary);
    my_free_char_2d(ary);
}

static int skin_tone(int player)
{
    if (player > 0)
        player -= 1;
    if (player < 0 || PLAYER_MAX <= player)
        return 0;
    prepare_change_skin(player);
    return 1;
}

int command_execute_change_player_skin_tone(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 2)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 2)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    return skin_tone(command_get_argument(command.ary[1], event));
}

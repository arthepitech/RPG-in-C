/*
** EPITECH PROJECT, 2022
** save/load_skin_tone.c
** File description:
** Loads the save - skin tone
*/

#include "calls.h"
#include "filepaths.h"
#include "items.h"
#include "my.h"
#include "palettes.h"
#include "struct.h"
#include <stdlib.h>

static void set_color(int const player, char * const *ary)
{
    sfColor tone = color_get(ary[GAME.player[player].skin_tone_id]);

    GAME.player[player].skin_tone.r = tone.r;
    GAME.player[player].skin_tone.g = tone.g;
    GAME.player[player].skin_tone.b = tone.b;
}

static void prepare_change_skin(int const id, int const player)
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
    *skin_tone_id = id % length;
    set_color(player, ary);
    my_free_char_2d(ary);
}

int load_skin_tone(int const id, int const player)
{
    prepare_change_skin(id, player);
    return id;
}

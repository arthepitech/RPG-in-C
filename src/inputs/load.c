/*
** EPITECH PROJECT, 2022
** inputs/load.c
** File description:
** Loads an input file
*/

#include "filepaths.h"
#include "inputs.h"
#include "my.h"
#include "struct.h"
#include <stdlib.h>
#include <SFML/Window/Joystick.h>

static void extract_line(char const *str, int const line)
{
    char **ary = NULL;

    if (line / 2 >= PLAYER_MAX)
        return;
    ary = my_str_to_array(str, " ");
    if (ary == NULL)
        return;
    for (int i = 0; ary[i] != NULL && i < INPUT_TOTAL_SIZE; i++) {
        if (line % 2 == 0)
            GAME.player[line / 2].inputs.keys[i] = my_str_to_int(ary[i]);
        else
            GAME.player[line / 2].inputs.buttons[i] = my_str_to_int(ary[i]);
    }
    my_free_char_2d(ary);
}

static void extract_infos(char * const *ary, int length)
{
    if (length > PLAYER_MAX * 2)
        length = PLAYER_MAX * 2;
    for (int i = 0; i < length; i++)
        extract_line(ary[i], i);
}

void inputs_load(char const *name)
{
    int length = 0;
    char **ary = NULL;

    ary = path_form_and_convert(name, PATH_SAVED);
    if (ary == NULL)
        return;
    for (length = 0; ary[length] != NULL; length++);
    extract_infos(ary, length);
    my_free_char_2d(ary);
}

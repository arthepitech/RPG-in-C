/*
** EPITECH PROJECT, 2022
** save/load.c
** File description:
** Loads the save
*/

#include "calls.h"
#include "filepaths.h"
#include "items.h"
#include "my.h"
#include "struct.h"
#include <stdlib.h>

static void load_player(char const *str, int const player)
{
    int length = 0;
    char **ary = NULL;

    if (str == NULL)
        return;
    ary = my_str_to_array(str, " ");
    if (ary == NULL)
        return;
    for (length = 0; ary[length] != NULL; length++);
    if (length >= 1)
        GAME.player[player].position.x = my_str_to_double(ary[0]);
    if (length >= 2)
        GAME.player[player].position.y = my_str_to_double(ary[1]);
    if (length >= 3) {
        load_skin_tone(my_str_to_int(ary[2]), player);
        GAME.player[player].skin_tone_id = my_str_to_int(ary[2]);
    }
    for (int i = 0; i < ITEM_TYPE_TOTAL_SIZE && (i + 3) < length; i++)
        GAME.player[player].equipment[i] = item_get(ary[i + 3]);
}

static void load_map(char const *str)
{
    char **ary = NULL;

    if (str == NULL)
        return;
    ary = my_str_to_array(str, " ");
    if (ary == NULL || ary[0] == NULL)
        return;
    if (GAME.map_next != NULL)
        free(GAME.map_next);
    GAME.map_next = DUP(ary[0]);
    GAME.map_next_position.x = -1;
    GAME.map_next_position.y = -1;
}

static void load_inventories(char const *str1, char const *str2)
{
    char **ary = NULL;

    if (str1 == NULL)
        return;
    ary = my_str_to_array(str1, " ");
    if (ary == NULL)
        return;
    for (int i = 0; ary[i] != NULL; i++)
        item_add(ary[i]);
    my_free_char_2d(ary);
    if (str2 == NULL)
        return;
    ary = my_str_to_array(str2, " ");
    if (ary == NULL)
        return;
    for (int i = 0; ary[i] != NULL; i++)
        music_add(ary[i]);
}

static void load_saved_variables(char const *str)
{
    int length = 0;
    char **ary = NULL;

    if (str == NULL)
        return;
    ary = my_str_to_array(str, " ");
    if (ary == NULL)
        return;
    for (length = 0; ary[length] != NULL; length++);
    for (int i = 0; i < SAVED_VARIABLES && i < length; i++)
        GAME.saved_variables[i] = my_str_to_int(ary[i]);
    my_free_char_2d(ary);
}

int save_load(char const *name)
{
    int length = 0;
    char **ary = path_form_and_convert(name, PATH_SAVED);

    if (ary == NULL)
        return 0;
    for (length = 0; ary[length] != NULL; length++);
    if (length >= 1)
        load_saved_variables(ary[0]);
    if (length >= 2)
        load_inventories(ary[1], ary[2]);
    if (length >= 4)
        load_map(ary[3]);
    for (int i = 0; i < PLAYER_MAX && (4 + i) < length; i++)
        load_player(ary[4 + i], i);
    my_free_char_2d(ary);
    return 1;
}

/*
** EPITECH PROJECT, 2022
** battle/enemy/get.c
** File description:
** Gets enemy informations
*/

#include "battles.h"
#include "filepaths.h"
#include "my.h"
#include "sound.h"
#include <stdlib.h>

static void extract_stats(battle_t *battle, char const *str)
{
    char **ary = NULL;
    int length = 0;

    if (str == NULL)
        return;
    ary = my_str_to_array(str, ENEMY_SEPARATORS);
    if (ary == NULL)
        return;
    for (length = 0; ary[length] != NULL; length++);
    for (int i = 0; i < STAT_TOTAL_SIZE && i < length; i++)
        battle->stats_enemy[i] = my_str_to_double(ary[i]);
}

static void extract_data(battle_t *battle, char * const *ary)
{
    int length = 0;

    if (ary == NULL)
        return;
    for (length = 0; ary[length] != NULL; length++);
    if (length >= 1)
        bgm_play(ary[0]);
    if (length >= 2)
        extract_stats(battle, ary[1]);
}

int battle_enemy_get(battle_t *battle, char const *name)
{
    char **ary = NULL;

    if (battle == NULL || name == NULL)
        return 0;
    ary = path_form_and_convert(name, PATH_ENEMIES);
    extract_data(battle, ary);
    my_free_char_2d(ary);
    return 1;
}

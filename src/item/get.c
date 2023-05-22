/*
** EPITECH PROJECT, 2022
** item/get.c
** File description:
** Search an item in files
*/

#include "filepaths.h"
#include "items.h"
#include "my.h"
#include <stdlib.h>

static void extract_sound(item_t *item, char const *arg)
{
    char **ary = NULL;
    int length = 0;

    ary = my_str_to_array(arg, ITEM_SEPARATORS);
    if (ary == NULL)
        return;
    for (length = 0; ary[length] != NULL; length++);
    if (length >= 1)
        item->sound_file = DUP(ary[0]);
    if (length >= 2)
        item->sound_volume = my_str_to_double(ary[1]);
}

static void extract_stats(item_t *item, char const *arg)
{
    sfTexture *texture = NULL;
    char **ary = NULL;
    int length = 0;

    ary = my_str_to_array(arg, ITEM_SEPARATORS);
    if (ary == NULL)
        return;
    for (length = 0; ary[length] != NULL; length++);
    for (int i = 0; i < length && i < STAT_TOTAL_SIZE; i++)
        item->stats[i] = my_str_to_int(ary[i]);
    my_free_char_2d(ary);
}

static void extract_infos(item_t *item, char * const *ary)
{
    int length = 0;

    for (length = 0; ary[length] != NULL; length++);
    if (length >= 1)
        item->name = DUP(ary[0]);
    if (length < 2)
        return;
    for (int i = 0; ITEM_TYPE_KEYS[i] != NULL; i++)
        if (my_strcmp(ary[1], ITEM_TYPE_KEYS[i]))
            item->type = i;
    if (length >= 3)
        item_extract_texture(item, ary[2]);
    if (length >= 4)
        extract_sound(item, ary[3]);
    if (length >= 5)
        extract_stats(item, ary[4]);
}

item_t *item_get(char const *name)
{
    char **ary = NULL;
    item_t *item = NULL;

    ary = path_form_and_convert(name, PATH_ITEMS);
    if (ary == NULL)
        return NULL;
    item = item_create();
    if (item == NULL) {
        my_free_char_2d(ary);
        return NULL;
    }
    item->file = DUP(name);
    extract_infos(item, ary);
    my_free_char_2d(ary);
    return item;
}

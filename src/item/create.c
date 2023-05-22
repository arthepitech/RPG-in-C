/*
** EPITECH PROJECT, 2022
** item/create.c
** File description:
** Creates an item
*/

#include "items.h"
#include <stdlib.h>

static void default_values(item_t *item)
{
    for (int i = 0; i < STAT_TOTAL_SIZE; i++)
        item->stats[i] = 0;
    for (int i = 0; i < ITEM_TAG_TOTAL_SIZE; i++)
        item->tags[i] = 0;
    item->cost = 0;
    item->file = NULL;
    item->name = NULL;
    item->palette = NULL;
    item->sound_file = NULL;
    item->sound_volume = ITEM_DEFAULT_VOLUME;
    item->texture = NULL;
    item->type = 0;
}

item_t *item_create(void)
{
    item_t *item = NULL;

    item = malloc(sizeof(item_t));
    if (item == NULL)
        return NULL;
    default_values(item);
    return item;
}

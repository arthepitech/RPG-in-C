/*
** EPITECH PROJECT, 2022
** item/destroy.c
** File description:
** Destroys an item
*/

#include "items.h"
#include "palettes.h"
#include <stdlib.h>

item_t *item_destroy(item_t *item)
{
    if (item == NULL)
        return NULL;
    if (item->file != NULL)
        free(item->file);
    if (item->name != NULL)
        free(item->name);
    if (item->sound_file != NULL)
        free(item->sound_file);
    if (item->palette != NULL)
        palette_destroy(item->palette);
    if (item->texture != NULL)
        sfTexture_destroy(item->texture);
    free(item);
    return NULL;
}

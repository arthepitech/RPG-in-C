/*
** EPITECH PROJECT, 2022
** item/get.c
** File description:
** Search an item in files
*/

#include "filepaths.h"
#include "files.h"
#include "items.h"
#include "my.h"
#include "palettes.h"
#include <stdlib.h>
#include <SFML/Graphics/Texture.h>

static void set_texture(item_t *item, char const *name)
{
    char *path = NULL;

    path = path_form(name, PATH_GRAPHICS);
    if (path == NULL)
        return;
    if (file_exists(path))
        item->texture = sfTexture_createFromFile(path, NULL);
    free(path);
}

static void extract_item_tag(item_t *item, char const *str)
{
    if (item == NULL || str == NULL)
        return;
    for (int i = 0; ITEM_TAG_KEYS[i] != NULL; i++)
        if (my_strcmp(str, ITEM_TAG_KEYS[i]))
            item->tags[i] = 1;
}

void item_extract_texture(item_t *item, char const *arg)
{
    sfTexture *texture = NULL;
    char **ary = NULL;
    int length = 0;

    ary = my_str_to_array(arg, ITEM_SEPARATORS);
    if (ary == NULL)
        return;
    for (length = 0; ary[length] != NULL; length++);
    if (length >= 1)
        set_texture(item, ary[0]);
    if (length >= 2)
        item->palette = palette_get(ary[1]);
    for (int i = 2; i < length; i++)
        extract_item_tag(item, ary[i]);
    my_free_char_2d(ary);
}

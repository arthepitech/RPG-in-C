/*
** EPITECH PROJECT, 2022
** palette/get.c
** File description:
** Search a palette in files
*/

#include "filepaths.h"
#include "files.h"
#include "my.h"
#include "palettes.h"
#include <stdlib.h>

static void pallette_extract(sfColor *color, char *name)
{
    sfColor picked_color = color_get(name);

    if (color == NULL)
        return;
    color->r = picked_color.r;
    color->g = picked_color.g;
    color->b = picked_color.b;
}

sfColor *palette_get(char const *name)
{
    char **ary = NULL;
    sfColor *palette = palette_create(sfMagenta, sfRed, sfWhite);

    if (palette == NULL)
        return NULL;
    ary = path_form_and_convert(name, PATH_PALETTES);
    if (ary == NULL)
        return palette;
    for (int i = 0; i < 3 && ary[i] != NULL; i++)
        pallette_extract(&palette[i], ary[i]);
    my_free_char_2d(ary);
    return palette;
}

/*
** EPITECH PROJECT, 2022
** color/get.c
** File description:
** Search a color in files
*/

#include "filepaths.h"
#include "my.h"
#include "palettes.h"
#include <stdlib.h>

static char *free_ary(char **ary)
{
    if (ary == NULL)
        return NULL;
    for (int i = 0; ary[i] != NULL; i++)
        free(ary[i]);
    free(ary);
    return NULL;
}

static int hexa_to_int(char const c1, char const c2)
{
    int value = 0;
    char hexa[] = "0123456789ABCDEF";

    for (int i = 0; hexa[i] != '\0'; i++) {
        if (c1 == hexa[i])
            value += i * 16;
        if (c2 == hexa[i])
            value += i;
    }
    return value;
}

static void convert_hexa(sfColor *color, char const *hexa)
{
    if (hexa == NULL)
        return;
    if (LEN(hexa) < 6)
        return;
    color->r = hexa_to_int(hexa[0], hexa[1]);
    color->g = hexa_to_int(hexa[2], hexa[3]);
    color->b = hexa_to_int(hexa[4], hexa[5]);
}

sfColor color_get(char const *name)
{
    sfColor color = sfWhite;
    char **ary = NULL;

    if (name == NULL)
        return color;
    ary = path_form_and_convert(name, PATH_COLORS);
    if (ary == NULL)
        return color;
    convert_hexa(&color, ary[0]);
    free_ary(ary);
    return color;
}

/*
** EPITECH PROJECT, 2022
** palette/create.c
** File description:
** Creates a palette
*/

#include <SFML/Graphics/Color.h>
#include <stdlib.h>

sfColor *palette_create(sfColor c1, sfColor c2, sfColor c3)
{
    sfColor *palette = NULL;

    palette = malloc(sizeof(sfColor) * 3);
    if (palette == NULL)
        return NULL;
    palette[0] = c1;
    palette[1] = c2;
    palette[2] = c3;
    return palette;
}

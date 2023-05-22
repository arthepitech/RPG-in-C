/*
** EPITECH PROJECT, 2022
** palette/destroy.c
** File description:
** Destroys a palette
*/

#include <SFML/Graphics/Color.h>
#include <stdlib.h>

sfColor *palette_destroy(sfColor *palette)
{
    if (palette == NULL)
        return NULL;
    free(palette);
    return NULL;
}

sfColor *palette_free(sfColor *palette)
{
    return palette_destroy(palette);
}

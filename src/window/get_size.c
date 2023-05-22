/*
** EPITECH PROJECT, 2022
** window/get_size.c
** File description:
** Create the window
*/

#include "struct.h"
#include <stdlib.h>

sfVector2f window_get_size_ratio(void)
{
    sfVector2f ratio = {1, 1};

    if (GAME.window_size.x > GAME.window_size.y)
        ratio.x = (float)GAME.window_size.y / GAME.window_size.x;
    else
        ratio.y = (float)GAME.window_size.x / GAME.window_size.y;
    return ratio;
}

sfVector2u window_get_size(void)
{
    sfVector2u size = GAME.window_size;
    sfVector2f ratio = window_get_size_ratio();

    size.x *= ratio.x;
    size.y *= ratio.y;
    return size;
}

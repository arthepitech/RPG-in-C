/*
** EPITECH PROJECT, 2022
** window/resize.c
** File description:
** Resizes the window if needed
*/

#include "const.h"
#include "my.h"
#include "struct.h"

static int do_resize(void)
{
    sfVector2u new_size = sfRenderWindow_getSize(GAME.window);

    new_size.x = MAX(MIN(new_size.x, WINDOW_SIZE_MIN.x), WINDOW_SIZE_MAX.x);
    new_size.y = MAX(MIN(new_size.y, WINDOW_SIZE_MIN.y), WINDOW_SIZE_MAX.y);
    sfRenderWindow_setSize(GAME.window, new_size);
    if (GAME.window_size.x == new_size.x && GAME.window_size.y == new_size.y)
        return 0;
    GAME.window_size.x = new_size.x;
    GAME.window_size.y = new_size.y;
    return 1;
}

int window_resize(void)
{
    if (GAME.window == NULL)
        return 0;
    return do_resize();
}

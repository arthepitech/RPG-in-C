/*
** EPITECH PROJECT, 2022
** window/is_open.c
** File description:
** Writing sfRender... is too long obviously, dah
*/

#include "struct.h"
#include <SFML/Graphics/RenderWindow.h>

sfBool window_is_open(void)
{
    if (GAME.window == NULL)
        return sfFalse;
    return sfRenderWindow_isOpen(GAME.window);
}

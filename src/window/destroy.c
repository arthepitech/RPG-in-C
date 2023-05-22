/*
** EPITECH PROJECT, 2022
** window/destroy.c
** File description:
** Destroy the window
*/

#include "struct.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/View.h>

void window_destroy(void)
{
    sfRenderWindow_destroy(GAME.window);
}

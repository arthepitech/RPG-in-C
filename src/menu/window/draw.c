/*
** EPITECH PROJECT, 2022
** menu/window/draw.c
** File description:
** Displays a menu window on screen
*/

#include "menus.h"
#include "tiles.h"
#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>

static int get_rect(menu_window_t *menu_window, int const x, int const y)
{
    int value = 0;

    if (x <= 0)
        value += 1;
    if (x >= menu_window->size.x - 1)
        value += 2;
    if (y <= 0)
        value += 4;
    if (y >= menu_window->size.y - 1)
        value += 8;
    return value;
}

static void draw_single_part(menu_window_t *menu_window, sfSprite *sprite,
int const x, int const y)
{
    menu_window->tile->position.x = menu_window->position.x + x;
    menu_window->tile->position.y = menu_window->position.y + y;
    menu_window->tile->texture_rect.x = 0;
    menu_window->tile->texture_rect.y = get_rect(menu_window, x, y);
    tile_draw_from_sprite(menu_window->tile, sprite, sfFalse);
}

void menu_window_draw(menu_window_t *menu_window)
{
    sfSprite *sprite = NULL;

    if (menu_window == NULL || menu_window->tile == NULL)
        return;
    if (menu_window->tile->texture == NULL)
        return;
    sprite = sfSprite_create();
    if (sprite == NULL)
        return;
    sfSprite_setTexture(sprite, menu_window->tile->texture, sfTrue);
    for (int i = 0; i < menu_window->size.x; i++)
        for (int j = 0; j < menu_window->size.y; j++)
            draw_single_part(menu_window, sprite, i, j);
    sfSprite_destroy(sprite);
}

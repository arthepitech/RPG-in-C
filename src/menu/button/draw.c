/*
** EPITECH PROJECT, 2022
** menu/button/draw.c
** File description:
** Displays a menu button on screen
*/

#include "const.h"
#include "menus.h"
#include "palettes.h"
#include "tiles.h"
#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

static void check_size(menu_button_t *menu_button)
{
    sfTexture *texture = NULL;

    if (menu_button->tile->texture == NULL)
        return;
    texture = menu_button->tile->texture;
    menu_button->texture_size.x = sfTexture_getSize(texture).x / TILE;
    menu_button->texture_size.y = sfTexture_getSize(texture).y / TILE;
}

static void draw_single_part(menu_button_t *menu_button, sfSprite *sprite,
int const i)
{
    char c = menu_button->text[i];
    char *text = menu_button->text;
    float spacing = MENU_BUTTON_SPACING[c % MENU_BUTTON_SPACING_SIZE] + 1;

    if (MENU_BUTTON_SPACING[c % MENU_BUTTON_SPACING_SIZE] <= 0)
        return;
    check_size(menu_button);
    menu_button->tile->texture_rect.x = c / menu_button->texture_size.y;
    menu_button->tile->texture_rect.y = c % menu_button->texture_size.y;
    menu_button->tile->texture_rect.x %= menu_button->texture_size.x;
    tile_draw_from_sprite(menu_button->tile, sprite, sfFalse);
    menu_button->tile->position.x += spacing * ((float)1 / TILE);
    menu_button->size.x += spacing;
    menu_button->size.y = TILE;
}

void menu_button_draw(menu_button_t *menu_button)
{
    sfSprite *sprite = NULL;

    if (menu_button == NULL || menu_button->tile == NULL)
        return;
    if (menu_button->tile->texture == NULL || menu_button->text == NULL)
        return;
    sprite = sfSprite_create();
    if (sprite == NULL)
        return;
    sfSprite_setTexture(sprite, menu_button->tile->texture, sfTrue);
    menu_button->size.x = 0;
    menu_button->size.y = 0;
    menu_button->tile->position.x = menu_button->position.x;
    menu_button->tile->position.y = menu_button->position.y;
    for (int i = 0; menu_button->text[i] != '\0'; i++)
        draw_single_part(menu_button, sprite, i);
    sfSprite_destroy(sprite);
}

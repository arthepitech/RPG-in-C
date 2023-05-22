/*
** EPITECH PROJECT, 2022
** tile/draw.c
** File description:
** Displays a tile on screen
*/

#include "const.h"
#include "struct.h"
#include "tiles.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>

static sfColor *get_color(tile_t const *tile)
{
    if (tile->palette_pointed != NULL && *(tile->palette_pointed) != NULL)
        return *(tile->palette_pointed);
    if (tile->palette != NULL)
        return tile->palette;
    return NULL;
}

static void draw(tile_t const *tile, sfSprite *sprite)
{
    sfIntRect cropping = {0, 0, TILE, TILE};
    sfColor *palette = get_color(tile);

    cropping.left += tile->texture_rect.x * TILE * 4;
    cropping.top += tile->texture_rect.y * TILE;
    for (int i = 0; i < 3; i++) {
        cropping.left += TILE;
        if (palette != NULL)
            sfSprite_setColor(sprite, palette[i]);
        sfSprite_setTextureRect(sprite, cropping);
        sfRenderWindow_drawSprite(GAME.window, sprite, NULL);
    }
}

static int configure(tile_t const *tile, sfSprite *sprite, int const destroy)
{
    sfVector2f position = {tile->position.x, tile->position.y};

    position.x = (int)(position.x * TILE);
    position.y = (int)(position.y * TILE);
    sfSprite_setPosition(sprite, position);
    draw(tile, sprite);
    if (destroy)
        sfSprite_destroy(sprite);
    return 1;
}

int tile_draw_from_sprite(tile_t const *tile, sfSprite *sprite,
sfBool const apply_texture)
{
    if (sprite == NULL)
        return 0;
    if (apply_texture) {
        if (tile->texture_pointed != NULL && *(tile->texture_pointed) != NULL)
            sfSprite_setTexture(sprite, *(tile->texture_pointed), sfTrue);
        else
            sfSprite_setTexture(sprite, tile->texture, sfTrue);
    }
    return configure(tile, sprite, 0);
}

int tile_draw(tile_t *tile)
{
    sfSprite *sprite = NULL;

    if (tile == NULL)
        return 0;
    sprite = sfSprite_create();
    if (sprite == NULL)
        return 0;
    if (tile->texture_pointed != NULL && *(tile->texture_pointed) != NULL)
        sfSprite_setTexture(sprite, *(tile->texture_pointed), sfTrue);
    else if (tile->texture != NULL)
        sfSprite_setTexture(sprite, tile->texture, sfTrue);
    return configure(tile, sprite, 1);
}

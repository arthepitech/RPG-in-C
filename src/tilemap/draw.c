/*
** EPITECH PROJECT, 2022
** tilemap/draw.c
** File description:
** Displays an entire tilemap on screen
*/

#include "tiles.h"
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>

static void draw_single(tilemap_t *tilemap, sfSprite *sprite,
int const x, int const y)
{
    if (tilemap->tile[x][y] == NULL)
        return;
    tilemap->tile[x][y]->position.x = x;
    tilemap->tile[x][y]->position.y = y;
    tile_draw_from_sprite(tilemap->tile[x][y], sprite, sfFalse);
}

void tilemap_draw_line(tilemap_t *tilemap, int const line)
{
    sfSprite *sprite = NULL;

    if (tilemap == NULL || line >= tilemap->size.y)
        return;
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, tilemap->texture, sfTrue);
    if (sprite == NULL)
        return;
    for (int i = 0; i < tilemap->size.x; i++)
            draw_single(tilemap, sprite, i, line);
    sfSprite_destroy(sprite);
}

void tilemap_draw(tilemap_t *tilemap)
{
    sfSprite *sprite = NULL;

    if (tilemap == NULL)
        return;
    sprite = sfSprite_create();
    if (sprite == NULL)
        return;
    sfSprite_setTexture(sprite, tilemap->texture, sfTrue);
    for (int i = 0; i < tilemap->size.x; i++)
        for (int j = 0; j < tilemap->size.y; j++)
            draw_single(tilemap, sprite, i, j);
    sfSprite_destroy(sprite);
}

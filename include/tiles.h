/*
** EPITECH PROJECT, 2022
** structures.h
** File description:
** Tiles used to display content in-game
*/

#pragma once
    #include "hitboxes.h"
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>

//A tile that can be displayed
//texture will be used only if texture_pointed is equal to NULL
//palette will be used only if palette_pointed is equal to NULL
typedef struct tile_s {
    sfTexture **texture_pointed;
    sfTexture *texture;
    sfColor **palette_pointed;
    sfColor *palette;
    sfVector2f position;
    sfVector2u texture_rect;
    hitbox_t *hitbox;
} tile_t;
//Contains a layer of a map
typedef struct tilemap_s {
    sfTexture *texture;
    sfVector2i size;
    tile_t ***tile;
} tilemap_t;

static const char TILEMAP_ENTRIES[] = ">";
static const char TILEMAP_SEPARATORS[] = "` \t";

int tilemap_check_collisions(tilemap_t const *t, float const x, float const y);
tile_t *tile_create(void);
//Returns NULL
tile_t *tile_destroy_with_pointers(tile_t *tile);
//Returns NULL
tile_t *tile_destroy(tile_t *tile);
int tile_draw_from_sprite(tile_t const *tile, sfSprite *sprite, sfBool const);
int tile_draw(tile_t *tile);
tilemap_t *tilemap_create(int x, int y);
//Returns NULL
tilemap_t *tilemap_destroy(tilemap_t *tilemap);
void tilemap_draw_line(tilemap_t *tilemap, int const line);
void tilemap_draw(tilemap_t *tilemap);
void tilemap_extract_tile(tile_t *tile, char const *str);
tilemap_t *tilemap_get(char const *name);

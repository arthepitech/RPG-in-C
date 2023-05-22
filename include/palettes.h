/*
** EPITECH PROJECT, 2022
** palettes.h
** File description:
** Color Palette from NES
*/

#pragma once
    #include "const.h"
    #include <SFML/Graphics/Color.h>

enum palette_layers_incides {
    COLOR_LAYER_MAIN,
    COLOR_LAYER_SECOND,
    COLOR_LAYER_SKIN,
    COLOR_LAYER_TOTAL,
};

static const char *PLAYER_DEFAULT_PALETTE = "player/0";
static const char *PLAYER_PALETTES[PLAYER_MAX] = {
    "player/1",
    "player/2",
    "player/3",
    "player/4",
};

sfColor color_get(char const *name);
sfColor *palette_create(sfColor c1, sfColor c2, sfColor c3);
sfColor *palette_destroy(sfColor *palette);
sfColor *palette_free(sfColor *palette);
sfColor *palette_get(char const *name);

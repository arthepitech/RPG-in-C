/*
** EPITECH PROJECT, 2022
** parallax/layer/create.c
** File description:
** Creates a new parallax layer
*/

#include "parallax.h"
#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>

static void default_values(parallax_layer_t *layer)
{
    if (layer == NULL)
        return;
    layer->speed = 0;
    layer->sprite = sfSprite_create();
    layer->texture = NULL;
}

parallax_layer_t *parallax_layer_create(void)
{
    parallax_layer_t *layer = NULL;

    layer = malloc(sizeof(parallax_layer_t));
    if (layer == NULL)
        return NULL;
    default_values(layer);
    if (layer->sprite != NULL)
        return layer;
    free(layer);
    return NULL;
}

/*
** EPITECH PROJECT, 2022
** parallax/layer/destroy.c
** File description:
** Destroy a parallax layer
*/

#include "parallax.h"
#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>

parallax_layer_t *parallax_layer_destroy(parallax_layer_t *layer)
{
    if (layer == NULL)
        return NULL;
    if (layer->sprite != NULL)
        sfSprite_destroy(layer->sprite);
    if (layer->texture != NULL)
        free(layer->texture);
    free(layer);
    return NULL;
}

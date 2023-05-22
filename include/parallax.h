/*
** EPITECH PROJECT, 2022
** parallax.h
** File description:
** Parallax-related things
*/

#pragma once
    #include <SFML/Graphics/Types.h>

typedef struct parallax_layer_s {
    sfSprite *sprite;
    char *texture;
    float speed;
} parallax_layer_t;

typedef struct parallax_s {
    parallax_layer_t **layer;
} parallax_t;

//Returns 0 if a problem is encountered
//Otherwise, returns 1
int parallax_destroy(void);
void parallax_initialise(void);
//Returns NULL if a problem is encountered
parallax_layer_t *parallax_layer_create(void);
//Returns NULL
parallax_layer_t *parallax_layer_destroy(parallax_layer_t *layer);

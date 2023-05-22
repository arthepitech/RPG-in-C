/*
** EPITECH PROJECT, 2022
** parallax/destroy.c
** File description:
** Destroys GAME.parallax data;
*/

#include "parallax.h"
#include "struct.h"
#include <stdlib.h>

int parallax_destroy(void)
{
    if (GAME.parallax.layer == NULL)
        return 0;
    for (int i = 0; GAME.parallax.layer[i] != NULL; i++)
        parallax_layer_destroy(GAME.parallax.layer[i]);
    free(GAME.parallax.layer);
    return 1;
}

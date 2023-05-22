/*
** EPITECH PROJECT, 2022
** hitbox/create.c
** File description:
** Creates a hitbox
*/

#include "hitboxes.h"
#include <stdlib.h>

hitbox_t *hitbox_create(void)
{
    hitbox_t *hitbox = NULL;

    hitbox = malloc(sizeof(hitbox_t));
    if (hitbox == NULL)
        return NULL;
    for (int i = 0; i < TILE; i++)
        for (int j = 0; j < TILE; j++)
            hitbox->ary[i][j] = HITBOX_DEFAULT_VALUE;
    return hitbox;
}

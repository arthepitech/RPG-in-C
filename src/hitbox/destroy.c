/*
** EPITECH PROJECT, 2022
** hitbox/destroy.c
** File description:
** Destroys a hitbox
*/

#include "hitboxes.h"
#include <stdlib.h>

hitbox_t *hitbox_destroy(hitbox_t *hitbox)
{
    if (hitbox == NULL)
        return NULL;
    free(hitbox);
    return NULL;
}

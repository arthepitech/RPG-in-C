/*
** EPITECH PROJECT, 2022
** hitbox/get.c
** File description:
** Creates a hitbox
*/

#include "filepaths.h"
#include "hitboxes.h"
#include "my.h"
#include <stdlib.h>

static int convert_char_to_int(char const c)
{
    for (int i = 0; HITBOX_CHAR[i] != 0; i++) {
        if (HITBOX_CHAR[i] == c)
            return i;
    }
    return HITBOX_CHAR_NULL;
}

static void fill_hitbox(hitbox_t *hitbox, char * const *ary)
{
    for (int i = 0; ary[i] != NULL && i < TILE; i++)
        for (int j = 0; ary[i][j] != '\0' && j < TILE; j++)
            hitbox->ary[i][j] = convert_char_to_int(ary[i][j]);
}

hitbox_t *hitbox_get(char const *name)
{
    char **ary = NULL;
    hitbox_t *hitbox = NULL;

    if (name == NULL)
        return NULL;
    hitbox = hitbox_create();
    if (hitbox == NULL)
        return NULL;
    ary = path_form_and_convert(name, PATH_HITBOXES);
    if (ary == NULL)
        return hitbox;
    fill_hitbox(hitbox, ary);
    my_free_char_2d(ary);
    return hitbox;
}

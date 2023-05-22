/*
** EPITECH PROJECT, 2022
** music/add.c
** File description:
** Adds an music in the score
*/

#include "items.h"
#include "my.h"
#include "struct.h"
#include <stdlib.h>

static int is_already_in(char const *name)
{
    char **inventory = GAME.score;

    if (inventory == NULL)
        return 0;
    for (int i = 0; inventory[i] != NULL; i++)
        if (my_strcmp(name, inventory[i]))
            return 1;
    return 0;
}

static int place_music(char const *name)
{
    char **inventory = GAME.score;
    char **new_inventory = NULL;
    int length = 0;

    if (inventory != NULL)
        for (length = 0; inventory[length] != NULL; length++);
    new_inventory = malloc(sizeof(char *) * (length + 2));
    if (new_inventory == NULL)
        return 0;
    for (int i = 0; i < length; i++)
        new_inventory[i] = inventory[i];
    new_inventory[length] = DUP(name);
    new_inventory[length + 1] = NULL;
    if (inventory != NULL)
        free(inventory);
    GAME.score = new_inventory;
    return 1;
}

int music_add(char const *name)
{
    if (name == NULL)
        return 0;
    if (is_already_in(name))
        return 0;
    return place_music(name);
}

/*
** EPITECH PROJECT, 2022
** item/add.c
** File description:
** Adds an item in the inventory
*/

#include "items.h"
#include "my.h"
#include "struct.h"
#include <stdlib.h>

static int get_item_type(char const *name)
{
    item_t *item = NULL;
    int item_type = -1;

    item = item_get(name);
    if (item != NULL) {
        item_type = item->type;
        item_destroy(item);
    }
    return item_type;
}

static int is_already_in(char const *name, int const item_type)
{
    char **inventory = GAME.inventory[item_type % ITEM_TYPE_TOTAL_SIZE];

    if (inventory == NULL)
        return 0;
    for (int i = 0; inventory[i] != NULL; i++)
        if (my_strcmp(name, inventory[i]))
            return 1;
    return 0;
}

static int place_item(char const *name, int const item_type)
{
    char **inventory = GAME.inventory[item_type % ITEM_TYPE_TOTAL_SIZE];
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
    GAME.inventory[item_type % ITEM_TYPE_TOTAL_SIZE] = new_inventory;
    return 1;
}

int item_add(char const *name)
{
    int item_type = 0;

    if (name == NULL)
        return 0;
    item_type = get_item_type(name);
    if (item_type < 0)
        return 0;
    if (is_already_in(name, item_type))
        return 0;
    return place_item(name, item_type);
}

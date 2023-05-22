/*
** EPITECH PROJECT, 2022
** menu/update_movement.c
** File description:
** Updates a menu for inputs etc.
*/

#include "calls.h"
#include "menus.h"
#include "my.h"
#include "struct.h"
#include "palettes.h"
#include <stdlib.h>
#include <SFML/Graphics/Texture.h>

static void change_color(menu_button_t *menu_button, char const *color)
{
    if (menu_button == NULL)
        return;
    if (menu_button->tile->palette_pointed != NULL) {
        free(*menu_button->tile->palette_pointed);
        menu_button->tile->palette_pointed = NULL;
    }
    if (color == NULL)
        return;
    menu_button->tile->palette_pointed = malloc(sizeof(sfColor *));
    if (menu_button->tile->palette_pointed == NULL)
        return;
    *menu_button->tile->palette_pointed = palette_get(color);
    if (*menu_button->tile->palette_pointed == NULL)
        free(menu_button->tile->palette_pointed);
}

static int movement_cursor(menu_t const *menu, int const plyr, int new,
int movement)
{
    while (movement > 0) {
        new += 1;
        if (menu->button[new] == NULL)
            new = 0;
        if (menu->button[new]->access < 0 || menu->button[new]->access == plyr)
            movement -= 1;
    }
    while (movement < 0) {
        new -= 1;
        if (new < 0) {
            for (new = 0; menu->button[new] != NULL; new++);
            new -= 1;
        }
        if (menu->button[new]->access < 0 || menu->button[new]->access == plyr)
            movement += 1;
    }
    return new;
}

static int move_cursor(menu_t const *menu, int const player, int new)
{
    if (GAME.player[player].inputs.press[INPUT_DOWN] == 1)
        return movement_cursor(menu, player, new, 1);
    if (GAME.player[player].inputs.press[INPUT_UP] == 1)
        return movement_cursor(menu, player, new, -1);
    return new;
}

static void force_update(menu_t *menu, int const player, int const id)
{
    for (int i = 0; i < PLAYER_MAX; i++) {
        if (menu->selected[i] == id && player != i) {
            change_color(menu->button[id], PLAYER_PALETTES[i]);
            return;
        }
    }
    change_color(menu->button[id], NULL);
}

void menu_update_movement(menu_t *menu, int const player)
{
    int new = menu->selected[player];

    new = move_cursor(menu, player, new);
    if (!GAME.player[player].connected)
        new = -1;
    if (new == menu->selected[player])
        return;
    if (menu->selected[player] >= 0)
        force_update(menu, player, menu->selected[player]);
    if (new >= 0)
        change_color(menu->button[new], PLAYER_PALETTES[player]);
    menu->selected[player] = new;
}

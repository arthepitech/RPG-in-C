/*
** EPITECH PROJECT, 2022
** menu/update.c
** File description:
** Updates a menu for inputs etc.
*/

#include "items.h"
#include "filepaths.h"
#include "menus.h"
#include "my.h"
#include "struct.h"
#include <stdlib.h>

static void execute_according_to_tags(menu_button_t *button)
{
    int battle_variable = SAVED_VARIABLES_BATTLE % SAVED_VARIABLES;
    int value = 0;

    value = button->tags[MENU_TAG_MATCHSOUNGNAME];
    if (value >= 1)
        GAME.saved_variables[battle_variable] = value - 1;
}

static int check_script_execute(menu_t *menu, int const player)
{
    if (menu->selected[player] < 0)
        return 0;
    if (GAME.player[player].inputs.press[INPUT_INTERACT] != 1)
        return 0;
    if (menu->button[menu->selected[player]]->script != NULL)
        script_execute(menu->button[menu->selected[player]]->script, NULL);
    menu_update_key(menu, menu->selected[player]);
    execute_according_to_tags(menu->button[menu->selected[player]]);
    if (menu->button[menu->selected[player]]->tags[MENU_TAG_CLOSE])
        menu->closing = sfTrue;
    return 1;
}

static int check_mouse_click(menu_t *menu, int const id)
{
    menu_button_t *button = menu->button[id];
    sfVector2f size = button->size;
    sfVector2f position = button->position;
    sfVector2f mouse = GAME.mouse_position;

    if (size.x <= 0 || size.y <= 0 || GAME.mouse_click != 1)
        return 0;
    if (mouse.x < position.x * TILE || position.x * TILE + size.x < mouse.x)
        return 0;
    if (mouse.y < position.y * TILE || position.y * TILE + size.y < mouse.y)
        return 0;
    if (button->script != NULL)
        script_execute(button->script, NULL);
    if (button->tags[MENU_TAG_CLOSE])
        menu->closing = sfTrue;
    menu_update_key(menu, id);
    execute_according_to_tags(button);
    GAME.mouse_click += 1;
    return 1;
}

void menu_update(menu_t *menu)
{
    if (menu == NULL || menu->button == NULL ||  menu->button[0] == NULL)
        return;
    for (int i = 0; menu->button[i] != NULL; i++)
        menu_update_name(menu->button[i]);
    for (int i = 0; i < PLAYER_MAX; i++) {
        menu_update_movement(menu, i);
        check_script_execute(menu, i);
    }
    for (int i = 0; menu->button[i] != NULL; i++)
        check_mouse_click(menu, i);
}

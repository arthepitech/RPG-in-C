/*
** EPITECH PROJECT, 2022
** menu/get_button.c
** File description:
** Used by menu_get.c for managing buttons
*/

#include "const.h"
#include "filepaths.h"
#include "event.h"
#include "menus.h"
#include "my.h"
#include "palettes.h"
#include "script.h"
#include "tiles.h"
#include <stdlib.h>

static void check_tags(menu_button_t *menu_button,
char const *str, char const *next)
{
    int id = -1;

    for (int i = 0; i < MENU_TAG_TOTAL_SIZE; i++) {
        if (my_strcmp(str, MENU_TAG_KEYS[i])) {
            menu_button->tags[i] = sfTrue;
            id = i;
        }
    }
    if (id < 0)
        return;
    for (int i = 0; MENU_TAG_ARGS[i] >= 0; i++)
        if (id == MENU_TAG_ARGS[i])
            menu_button->tags[id] = my_str_to_int(next);
}

static void extract_args(menu_button_t *menu_button, char * const *ary)
{
    int length = 0;

    for (length = 0; ary[length] != NULL; length++);
    if (length >= 2)
        menu_button->text = DUP(ary[1]);
    if (length >= 3)
        menu_button->tile->palette = palette_get(ary[2]);
    if (length >= 4)
        menu_button->position.x = my_str_to_double(ary[3]);
    if (length >= 5)
        menu_button->position.y = my_str_to_double(ary[4]);
    if (length >= 6)
        menu_button->script = script_get(ary[5]);
    if (length >= 7)
        menu_button->access = my_str_to_int(ary[6]) - 1;
    for (int i = 7; i < length; i++)
        check_tags(menu_button, ary[i], ary[i + 1]);
}

static void align_with_window(menu_t const *menu, menu_button_t *menu_button)
{
    int id = 0;

    if (menu == NULL || menu->window == NULL)
        return;
    for (id = 0; menu->window[id] != NULL; id++);
    if (id <= 0)
        return;
    menu_button->position.x += menu->window[id - 1]->position.x;
    menu_button->position.y += menu->window[id - 1]->position.y;
}

static menu_button_t *extract_button(char * const *ary)
{
    menu_button_t *menu_button = menu_button_create();

    if (menu_button == NULL)
        return NULL;
    menu_button->tile = menu_button_create_default_tile();
    if (menu_button->tile == NULL)
        return NULL;
    extract_args(menu_button, ary);
    return menu_button;
}

void menu_get_button(menu_t *menu, char * const *ary)
{
    menu_button_t *menu_button = NULL;
    int id = 0;

    if (menu == NULL || menu->button == NULL || ary == NULL || ary[0] == NULL)
        return;
    menu_button = extract_button(ary);
    if (menu_button == NULL)
        return;
    align_with_window(menu, menu_button);
    for (id = 0; menu->button[id] != NULL; id++);
    menu->button[id] = menu_button;
}

/*
** EPITECH PROJECT, 2022
** menu/update_name.c
** File description:
** Updates a menu for inputs etc., but only names
*/

#include "items.h"
#include "filepaths.h"
#include "inputs.h"
#include "menus.h"
#include "my.h"
#include "struct.h"
#include <stdlib.h>

static void s_name(menu_button_t const *menu_button, int const menu_tag,
int const item_type, char **new_text)
{
    int player = menu_button->access;
    item_t const *item = GAME.player[player].equipment[item_type];

    if (*new_text != NULL || !menu_button->tags[menu_tag] || item == NULL)
        return;
    if (menu_button->text != NULL && my_strcmp(menu_button->text, item->name))
        return;
    *new_text = DUP(item->name);
}

static char *search_input_text(char const *name, int const value)
{
    int length = 0;
    char *str = NULL;
    char **ary = NULL;

    str = path_form(FILE_CONTROLLER_TXT, PATH_TEXT);
    if (str == NULL || value < 0)
        return NULL;
    ary = path_form_and_convert(name, PATH_TEXT);
    free(str);
    str = NULL;
    if (ary == NULL)
        return NULL;
    for (length = 0; ary[length] != NULL; length++);
    if (value < length)
        str = DUP(ary[value]);
    my_free_char_2d(ary);
    return str;
}

static void s_stat(menu_button_t const *menu_button, int const stat,
char **new_text)
{
    char *str1 = NULL;
    char *str2 = NULL;

    if (*new_text != NULL || stat < 0)
        return;
    str1 = my_int_to_str(item_get_stats(stat));
    if (str1 == NULL)
        return;
    str2 = my_strcat(STAT_NAMES[stat], str1);
    free(str1);
    if (str2 == NULL)
        return;
    str1 = my_strcat(str2, STAT_SUFFIXES[stat ]);
    free(str2);
    if (str1 != NULL)
        *new_text = str1;
}

static void s_input(menu_button_t const *menu_button, int const menu_tag,
char **new_text)
{
    int player = menu_button->access;
    int id = menu_button->tags[menu_tag] - 1;
    char *text = NULL;
    inputs_t *inputs = &GAME.player[player].inputs;

    if (*new_text != NULL || menu_button->tags[menu_tag] <= 0)
        return;
    if (menu_button->tags[menu_tag] - 1 >= INPUT_TOTAL_SIZE)
        return;
    if (menu_tag == MENU_TAG_MATCHBUT)
        text = search_input_text(FILE_CONTROLLER_TXT, inputs->buttons[id]);
    else
        text = search_input_text(FILE_KEYBOARD_TXT, inputs->keys[id]);
    if (text != NULL)
        *new_text = text;
}

void menu_update_name(menu_button_t *menu_button)
{
    int player = menu_button->access;
    menu_button_t *button = menu_button;
    char *text = NULL;

    if (player >= 0 && player < PLAYER_MAX) {
        s_name(button, MENU_TAG_MATCHINSTRUMENT, ITEM_TYPE_INSTRUMENT, &text);
        s_name(button, MENU_TAG_MATCHOUTFIT, ITEM_TYPE_OUTFIT, &text);
        s_input(button, MENU_TAG_MATCHBUT, &text);
        s_input(button, MENU_TAG_MATCHKEY, &text);
    }
    s_stat(button, button->tags[MENU_TAG_MATCHSTAT] - 1, &text);
    if (text == NULL)
        return;
    if (button->text != NULL)
        free(button->text);
    button->text = text;
}

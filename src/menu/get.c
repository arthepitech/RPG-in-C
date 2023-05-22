/*
** EPITECH PROJECT, 2022
** menu/get.c
** File description:
** Search a menu in files
*/

#include "filepaths.h"
#include "menus.h"
#include "my.h"
#include <stdlib.h>

static int get_elem_type(char const *str, sfBool const decompose)
{
    char *str_used = DUP(str);
    char **ary = NULL;
    char const *types[3] = {MENU_BUTTON_KEY, MENU_EVENT_KEY, MENU_WINDOW_KEY};

    if (decompose) {
        ary = my_str_to_array(str, MENU_SEPARATORS);
        if (ary == NULL)
            return -1;
        free(str_used);
        str_used = DUP(ary[0]);
        my_free_char_2d(ary);
    }
    for (int i = 0; i < 3; i++)
        if (my_strcmp(str_used, types[i])) {
            free(str_used);
            return i;
        }
    if (str_used != NULL)
        free(str_used);
    return -1;
}

static void use_malloc(menu_t *menu, int const *lengths)
{
    if (lengths[0] > 0)
        menu->button = malloc(sizeof(menu_button_t *) * (lengths[0] + 1));
    if (lengths[1] > 0)
        menu->event = malloc(sizeof(event_t *) * (lengths[1] + 1));
    if (lengths[2] > 0)
        menu->window = malloc(sizeof(menu_window_t *) * (lengths[2] + 1));
    if (menu->button != NULL)
        for (int i = 0; i < (lengths[0] + 1); i++)
            menu->button[i] = NULL;
    if (menu->event != NULL)
        for (int i = 0; i < (lengths[1] + 1); i++)
            menu->event[i] = NULL;
    if (menu->window != NULL)
        for (int i = 0; i < (lengths[2] + 1); i++)
            menu->window[i] = NULL;
}

static void malloc_elements(menu_t *menu, char * const *ary)
{
    int type = 0;
    int lengths[3] = {0, 0, 0};

    for (int i = 0; ary[i] != NULL; i++) {
        type = get_elem_type(ary[i], sfTrue);
        if (0 <= type && type < 3)
            lengths[type % 3] += 1;
    }
    use_malloc(menu, lengths);
}

static void extract_menu(menu_t *menu, char * const *ary)
{
    char **ary2_line = NULL;

    malloc_elements(menu, ary);
    for (int i = 0; ary[i] != NULL; i++) {
        ary2_line = my_str_to_array(ary[i], MENU_SEPARATORS);
        if (ary2_line != NULL && my_strcmp(ary2_line[0], MENU_BUTTON_KEY))
            menu_get_button(menu, ary2_line);
        if (ary2_line != NULL && my_strcmp(ary2_line[0], MENU_EVENT_KEY))
            menu_get_event(menu, ary2_line);
        if (ary2_line != NULL && my_strcmp(ary2_line[0], MENU_WINDOW_KEY))
            menu_get_window(menu, ary2_line);
        if (ary2_line != NULL)
            my_free_char_2d(ary2_line);
    }
}

menu_t *menu_get(char const *name)
{
    menu_t *menu = NULL;
    char **ary = NULL;

    if (name == NULL)
        return NULL;
    menu = menu_create();
    if (menu == NULL)
        return NULL;
    ary = path_form_and_convert(name, PATH_MENUS);
    if (ary == NULL) {
        menu_destroy(menu);
        return NULL;
    }
    extract_menu(menu, ary);
    my_free_char_2d(ary);
    return menu;
}

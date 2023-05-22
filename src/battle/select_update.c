/*
** EPITECH PROJECT, 2022
** battle/select_update.c
** File description:
** Select a music
*/

#include "battles.h"
#include "filepaths.h"
#include "menu.h"
#include "my.h"
#include <stdlib.h>

static void update_button_text(menu_button_t *button, char const *name)
{
    if (button == NULL || name == NULL)
        return;
    if (button->text != NULL)
        free(button->text);
    button->text = DUP(name);
}

static void set_button(menu_button_t *button, char * const *ary, int const id)
{
    int length = 0;
    char **ary2 = NULL;

    if (ary == NULL || ary[0] == NULL)
        return;
    ary2 = my_str_to_array(ary[0], SONG_SEPARATORS);
    if (ary2 == NULL)
        return;
    for (length = 0; ary2[length] != NULL; length++);
    if (length >= 1 && button->tags[MENU_TAG_MATCHSOUNGNAME] - 1 == id)
        update_button_text(button, ary2[0]);
    if (length >= 2 && button->tags[MENU_TAG_MATCHSOUNGDMG] - 1 == id)
        update_button_text(button, ary2[1]);
    if (length >= 3 && button->tags[MENU_TAG_MATCHSOUNGCRIT] - 1 == id)
        update_button_text(button, ary2[2]);
    my_free_char_2d(ary2);
}

static void button_default(battle_t *battle, menu_button_t *button)
{
    int id = 0;
    char *text = NULL;

    if (button == NULL || battle == NULL)
        return;
    if (text == NULL && button->tags[MENU_TAG_MATCHALLYSTAT] > 0) {
        id = button->tags[MENU_TAG_MATCHALLYSTAT] - 1;
        text = my_int_to_str((int)battle->stats_ally[id % STAT_TOTAL_SIZE]);
        update_button_text(button, text);
    }
    if (text == NULL && button->tags[MENU_TAG_MATCHENEMYSTAT] > 0) {
        id = button->tags[MENU_TAG_MATCHENEMYSTAT] - 1;
        text = my_int_to_str((int)battle->stats_enemy[id % STAT_TOTAL_SIZE]);
        update_button_text(button, text);
    }
    if (text == NULL)
        free(text);
}

void battle_select_update(battle_t *battle, menu_t *menu,
char * const *selection)
{
    char **ary = NULL;

    if (menu == NULL || menu->button == NULL || selection == NULL)
        return;
    for (int i = 0; menu->button[i] != NULL; i++)
        button_default(battle, menu->button[i]);
    for (int i = 0; i < BATTLE_SELECTION; i++) {
        ary = path_form_and_convert(selection[i], PATH_MUSICS);
        for (int j = 0; menu->button[j] != NULL; j++)
            set_button(menu->button[j], ary, i);
        if (ary != NULL)
            my_free_char_2d(ary);
    }
}

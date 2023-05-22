/*
** EPITECH PROJECT, 2022
** battle/select.c
** File description:
** Select a music
*/

#include "battles.h"
#include "filepaths.h"
#include "menu.h"
#include "my.h"
#include "sound.h"
#include "struct.h"
#include <stdlib.h>

static void play_soung(battle_t *battle, char const *name)
{
    if (name == NULL)
        return;
    battle->note_accuracy = 0;
    battle->note_total = 0;
    for (int i = 0; i < PLAYER_MAX; i++)
        if (GAME.player[i].connected)
            battle->note[i] = battle_song_get(battle, name);
}

static int open_select_menu(battle_t *battle, char * const *selection)
{
    int variable = 0;
    int slct = SAVED_VARIABLES_BATTLE % SAVED_VARIABLES;
    menu_t *menu = NULL;

    GAME.saved_variables[slct] = -1;
    menu = menu_get(FILE_BATTLE_SELECT);
    if (menu == NULL)
        return -1;
    if (GAME.bgm.music != NULL)
        sfMusic_setVolume(GAME.bgm.music, BGM_DEFAULT_VOLUME);
    battle_select_update(battle, menu, selection);
    while (window_is_open() && GAME.saved_variables[slct] < 0)
        menu_open_loop(menu);
    menu_destroy(menu);
    return GAME.saved_variables[slct];
}

static int is_in_selection(char * const *selection, char const *name)
{
    for (int i = 0; i < BATTLE_SELECTION; i++) {
        if (selection[i] != NULL && my_strcmp(selection[i], name))
            return 1;
    }
    return 0;
}

static void select_songs(char **selection)
{
    int length = 0;
    int id = 0;
    int corresponds = 0;

    if (selection == NULL || GAME.score == NULL)
        return;
    for (length = 0; GAME.score[length] != NULL; length++);
    for (int i = 0; i < BATTLE_SELECTION && i < length; i++) {
        corresponds = 1;
        for (int j = 0; j < BATTLE_RANDOM_TRIES && corresponds; j++) {
            id = rand() % length;
            corresponds = is_in_selection(selection, GAME.score[id]);
        }
        selection[i] = DUP(GAME.score[id]);
    }
}

int battle_select(battle_t *battle)
{
    int selected = 0;
    char *selection[BATTLE_SELECTION];

    for (int i = 0; i < BATTLE_SELECTION; i++)
        selection[i] = NULL;
    select_songs(selection);
    if (battle == NULL)
        return 0;
    selected = open_select_menu(battle, selection);
    if (selected < 0 || selected >= BATTLE_SELECTION)
        return 0;
    if (GAME.bgm.music != NULL)
        sfMusic_setVolume(GAME.bgm.music, BGM_BATTLE_VOLUME);
    play_soung(battle, selection[selected]);
    for (int i = 0; i < BATTLE_SELECTION; i++)
        if (selection[i] != NULL)
            free(selection[i]);
    return 1;
}

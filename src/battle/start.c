/*
** EPITECH PROJECT, 2022
** battle/start.c
** File description:
** It's time, to du-du-du-duel
*/

#include "battles.h"
#include "calls.h"
#include "sound.h"
#include "filepaths.h"
#include "menus.h"
#include "my.h"
#include "struct.h"
#include <stdlib.h>

static void check_event_calls(menu_t *menu)
{
    if (menu == NULL || menu->event == NULL)
        return;
    for (int i = 0; menu->event[i] != NULL; i++)
        event_execute(menu->event[i], CALL_ONTICK);
}

static void display_battle(battle_t *battle)
{
    if (!window_is_open())
        return;
    window_resize();
    sfRenderWindow_clear(GAME.window, sfBlack);
    tick_change_view(-1);
    menu_draw(battle->menu);
    battle_notes_draw(battle);
    sfRenderWindow_display(GAME.window);
}

static int deal_damages(battle_t *battle)
{
    float damage = 0;

    if (battle == NULL || battle_is_playing(battle) || battle->note_total < 1)
        return 0;
    battle->stats_ally[STAT_HEALTH] -= battle->stats_enemy[STAT_ATTACK];
    battle->damage[DAMAGE_ACCURACY] *= battle->note_accuracy;
    for (int i = 0; i < DAMAGE_TOTAL_SIZE; i++)
        damage += battle->damage[i] * (battle->stats_ally[STAT_ATTACK] / 100);
    battle->stats_enemy[STAT_HEALTH] -= MIN(damage, 0);
    battle->note_total = 0;
    if (battle->stats_enemy[STAT_HEALTH] <= 0) {
        GAME.saved_variables[SAVED_VARIABLES_BATTLE] = BATTLE_WIN;
        return 1;
    }
    if (battle->stats_ally[STAT_HEALTH] <= 0) {
        GAME.saved_variables[SAVED_VARIABLES_BATTLE] = BATTLE_LOOSE;
        return 1;
    }
    return 0;
}

static int loop_game(battle_t *battle)
{
    if (deal_damages(battle))
        return 0;
    while (!battle_is_playing(battle))
        if (!battle_select(battle))
            return 0;
    tick_poll_events();
    tick_deltaclock();
    tick_player_inputs();
    tick_map_change();
    menu_update(battle->menu);
    battle_notes_update(battle);
    check_event_calls(battle->menu);
    display_battle(battle);
    return 1;
}

int battle_start(char const *name)
{
    battle_t *battle = battle_create();

    bgm_free();
    if (!battle_enemy_get(battle, name)) {
        battle_destroy(battle);
        return 0;
    }
    battle->menu = menu_get(FILE_BATTLE_ZONES);
    while (window_is_open() && loop_game(battle));
    battle_destroy(battle);
    bgm_free();
    if (GAME.map != NULL && GAME.map->bgm != NULL)
        bgm_play(GAME.map->bgm);
    return 1;
}

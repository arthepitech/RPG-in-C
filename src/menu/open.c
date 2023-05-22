/*
** EPITECH PROJECT, 2022
** menu/open.c
** File description:
** Opens an entire menu (trutst me that's huge)
*/

#include "calls.h"
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

static int check_close_menu(menu_t const *menu)
{
    for (int i = 0; i < PLAYER_MAX; i++)
        if (GAME.player[i].inputs.press[INPUT_RETURN] == 1) {
            GAME.player[i].inputs.press[INPUT_RETURN] += 1;
            return 1;
        }
    if (menu->closing)
        return 1;
    return 0;
}

static void display_menu(menu_t *menu)
{
    if (!window_is_open())
        return;
    window_resize();
    sfRenderWindow_clear(GAME.window, sfBlack);
    tick_draw_map();
    tick_change_view(-1);
    menu_draw(menu);
    sfRenderWindow_display(GAME.window);
}

void menu_open_loop(menu_t *menu)
{
    while (window_is_open()) {
        tick_poll_events();
        tick_deltaclock();
        tick_player_inputs();
        tick_map_change();
        menu_update(menu);
        map_execute(GAME.map, CALL_ONTICK);
        check_event_calls(menu);
        display_menu(menu);
        if (check_close_menu(menu))
            return;
    }
}

int menu_open(char const *name)
{
    menu_t *menu = menu_get(name);

    if (menu == NULL)
        return 0;
    menu_open_loop(menu);
    menu_destroy(menu);
    return 1;
}

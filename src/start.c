/*
** EPITECH PROJECT, 2022
** start.c
** File description:
** Main function
*/

#include "battles.h"
#include "calls.h"
#include "const.h"
#include "files.h"
#include "filepaths.h"
#include "inputs.h"
#include "maps.h"
#include "my.h"
#include "script.h"
#include "struct.h"
#include <stddef.h>
#include <SFML/Graphics/RenderWindow.h>

static int check_open_menu(void)
{
    int players_connected = 0;

    for (int i = 0; i < PLAYER_MAX; i++) {
        if (GAME.player[i].connected)
            players_connected += 1;
        if (GAME.player[i].inputs.press[INPUT_RETURN] == 1) {
            script_call(SCRIPT_SYSTEM_OPEN_MENU, NULL);
            return 1;
        }
    }
    if (players_connected <= 0) {
        script_call(SCRIPT_SYSTEM_OPEN_MENU, NULL);
        return 1;
    }
    return 0;
}

static void loop_game(void)
{
    tick_poll_events();
    tick_deltaclock();
    tick_player_inputs();
    tick_map_change();
    tick_player_movement();
    tick_events_update_calls();
    map_execute(GAME.map, CALL_ONTICK);
    window_resize();
    sfRenderWindow_clear(GAME.window, sfBlack);
    tick_draw_map();
    sfRenderWindow_display(GAME.window);
    check_open_menu();
}

int start(void)
{
    game_initialise();
    window_create(0);
    save_load(FILE_SAVE);
    if (GAME.map_next != NULL)
        free(GAME.map_next);
    GAME.map_next = NULL;
    srand((long int)&GAME * 2 - (long int)&GAME.window);
    while (window_is_open()) {
        while (window_is_open() && GAME.map == NULL)
            script_call(SCRIPT_SYSTEM_INIT, NULL);
        loop_game();
    }
    inputs_save(FILE_INPUTS);
    if (GAME.map != NULL)
        save_save(FILE_SAVE);
    game_free();
    if (GAME.window != NULL)
        sfRenderWindow_destroy(GAME.window);
    return EXIT;
}

/*
** EPITECH PROJECT, 2022
** initialise.c
** File description:
** Initalise for the first time GAME
*/

#include "filepaths.h"
#include "inputs.h"
#include "struct.h"
#include <stddef.h>
#include <SFML/System/Clock.h>

static void intialise_inputs(player_t *player, int const input)
{
    player->inputs.buttons[input] = -1;
    player->inputs.keys[input] = -1;
    player->inputs.press[input] = 0;
}

static void initialise_player(player_t *player)
{
    for (int i = 0; i < INPUT_TOTAL_SIZE; i++)
        intialise_inputs(player, i);
    for (int i = 0; i < ITEM_TYPE_TOTAL_SIZE; i++)
        player->equipment[i] = NULL;
    player->connected = 0;
    player->deltawalking = 0;
    player->direction = 0;
    player->inputs.input_type = INPUT_TYPE_KEYBOARD;
    player->position.x = 0;
    player->position.y = 0;
    player->skin_tone = sfWhite;
    player->skin_tone_id = 0;
}

static void initialise_nulls(void)
{
    for (int i =  0; i < ITEM_TYPE_TOTAL_SIZE; i++)
        GAME.inventory[i] = NULL;
    GAME.map = NULL;
    GAME.map_next = NULL;
    GAME.score = NULL;
    GAME.window = NULL;
    parallax_initialise();
}

static void initialise_zeros(void)
{
    for (int i = 0; i < SAVED_VARIABLES; i++)
        GAME.saved_variables[i] = SAVED_VARIABLES_DEFAULT;
    GAME.map_next_position.x = 0;
    GAME.map_next_position.y = 0;
    GAME.mouse_click = 0;
    GAME.mouse_position.x = 0;
    GAME.mouse_position.y = 0;
    GAME.window_fullscreen = 0;
    GAME.window_size.x = 0;
    GAME.window_size.y = 0;
}

void game_initialise(void)
{
    GAME.deltaclock = sfClock_create();
    GAME.delta = 0;
    for (int i = 0; i < PLAYER_MAX; i++)
        initialise_player(&GAME.player[i]);
    GAME.window_focus = sfTrue;
    GAME.window_force_close = sfFalse;
    initialise_zeros();
    initialise_nulls();
    bgm_initialise();
    inputs_load(FILE_INPUTS);
}

/*
** EPITECH PROJECT, 2022
** tick/player/inputs.c
** File description:
** Manage player inputs
*/

#include "calls.h"
#include "inputs.h"
#include "my.h"
#include "struct.h"
#include <stddef.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>

static int is_pressed(char const player, int const input)
{
    inputs_t *input_struct = &GAME.player[player].inputs;
    int id = MIN(input_struct->input_type, 0);
    int button = MIN(input_struct->buttons[input], 0);

    if (!GAME.player[player].connected)
        return 0;
    if (input_struct->input_type == INPUT_TYPE_KEYBOARD) {
        if (sfKeyboard_isKeyPressed(input_struct->keys[input]))
            return 1;
        else
            return 0;
    } else {
        if (sfJoystick_isButtonPressed(id, button))
            return 1;
        else
            return 0;
    }
    return 0;
}

static int is_inputed(char const player, int const input, float const *inputs)
{
    int returned = is_pressed(player, input);

    if (returned)
        return 1;
    if (inputs[input] > 0)
        return 1;
    return 0;
}

static void check_single_player(char const player)
{
    float inputs[INPUT_TOTAL_SIZE];

    for (int i = 0; i < INPUT_TOTAL_SIZE; i++)
        inputs[i] = 0;
    tick_player_input_joysticks(player, inputs);
    for (int i = 0; i < INPUT_TOTAL_SIZE; i++) {
        if (is_inputed(player, i, inputs))
            GAME.player[player].inputs.press[i] += 1;
        else
            GAME.player[player].inputs.press[i] = 0;
    }
}

void tick_player_inputs(void)
{
    if (!GAME.window_focus)
        return;
    if (sfMouse_isButtonPressed(sfMouseLeft))
        GAME.mouse_click += 1;
    else
        GAME.mouse_click = 0;
    inputs_update();
    for (int i = 0; i < PLAYER_MAX; i++)
        check_single_player(i);
}

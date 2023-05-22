/*
** EPITECH PROJECT, 2022
** inputs/update.c
** File description:
** Updates players' inputs
*/

#include "const.h"
#include "inputs.h"
#include "my.h"
#include "struct.h"
#include <stdlib.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>

static int check_new_keyboard(int const player)
{
    inputs_t *player_struct = &GAME.player[player].inputs;
    int no_input = 1;

    for (int i = 0; i < INPUT_TOTAL_SIZE; i++)
        if (no_input && sfKeyboard_isKeyPressed(player_struct->keys[i]))
            no_input = 0;
    if (sfKeyboard_isKeyPressed(player_struct->keys[INPUT_QUIT]))
        no_input = 1;
    if (no_input)
        return 0;
    GAME.player[player].connected = 1;
    GAME.player[player].inputs.input_type = INPUT_TYPE_KEYBOARD;
    return 1;
}

static int check_disconnect(int const player)
{
    inputs_t *player_struct = &GAME.player[player].inputs;
    int controller = MIN(GAME.player[player].inputs.input_type, 0);
    int disconnect = 0;
    int button = MIN(player_struct->buttons[INPUT_QUIT], 0);

    if (player_struct->input_type == INPUT_TYPE_KEYBOARD) {
        if (sfKeyboard_isKeyPressed(player_struct->keys[INPUT_QUIT]))
            disconnect = 1;
    } else {
        if (sfJoystick_isButtonPressed(controller, button))
            disconnect = 1;
        if (!sfJoystick_isConnected(controller))
            disconnect = 1;
    }
    if (!disconnect)
        return 0;
    GAME.player[player].connected = 0;
    return 1;
}

void inputs_update(void)
{
    for (int i = 0; i < PLAYER_MAX; i++) {
        if (!GAME.player[i].connected)
            check_new_keyboard(i);
        else
            check_disconnect(i);
    }
    for (int i = 0; i <= sfJoystickCount; i++)
        if (sfJoystick_isConnected(i))
            inputs_new_controller(i);
    for (int i = 0; i < PLAYER_MAX; i++)
            check_disconnect(i);
}

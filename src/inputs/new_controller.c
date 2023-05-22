/*
** EPITECH PROJECT, 2022
** inputs/new_controller.c
** File description:
** Tries to add a new controller
*/

#include "const.h"
#include "inputs.h"
#include "struct.h"
#include <stdlib.h>
#include <SFML/Window/Joystick.h>

static int new_controller_player(int const id)
{
    for (int i = 0; i < PLAYER_MAX; i++)
        if (GAME.player[i].connected && GAME.player[i].inputs.input_type == id)
            return -1;
    for (int i = 0; i < PLAYER_MAX; i++)
        if (!GAME.player[i].connected)
            return i;
    return -1;
}

int inputs_new_controller(int const id)
{
    int player = new_controller_player(id);
    int no_input = 1;
    int input_count = 0;

    if (player < 0)
        return 0;
    input_count = sfJoystick_getButtonCount(id);
    for (int i = 0; i < input_count; i++)
        if (no_input && sfJoystick_isButtonPressed(id, i))
            no_input = 0;
    if (no_input)
        return 0;
    GAME.player[player].connected = 1;
    GAME.player[player].inputs.input_type = id;
    return 1;
}

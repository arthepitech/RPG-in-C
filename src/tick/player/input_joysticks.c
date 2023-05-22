/*
** EPITECH PROJECT, 2022
** tick/player/movement_controller.c
** File description:
** Set inputs from joysticks
*/

#include "inputs.h"
#include "my.h"
#include "struct.h"
#include <stddef.h>
#include <SFML/Window/Joystick.h>

static void from_axis(int const id, float *inf, float *sup, int const axis)
{
    float value = sfJoystick_getAxisPosition(id, axis);

    if (0 - INPUT_JOYSTICK_MIN < value && value < INPUT_JOYSTICK_MIN)
        return;
    value = (value * 100) / INPUT_JOYSTICK_MAX;
    if (value > 0)
        *sup = MAX(ABS(value), 100) / 100;
    if (value < 0)
        *inf = MAX(ABS(value), 100) / 100;
}

void tick_player_input_joysticks(int const player, float *inputs)
{
    player_t *player_struct = &GAME.player[player];
    int id = player_struct->inputs.input_type;

    if (!player_struct->connected || inputs == NULL)
        return;
    if (player_struct->inputs.input_type == INPUT_TYPE_KEYBOARD)
        return;
    from_axis(id, &inputs[INPUT_LEFT], &inputs[INPUT_RIGHT], sfJoystickPovX);
    from_axis(id, &inputs[INPUT_UP], &inputs[INPUT_DOWN], sfJoystickPovY);
    from_axis(id, &inputs[INPUT_LEFT], &inputs[INPUT_RIGHT], sfJoystickX);
    from_axis(id, &inputs[INPUT_UP], &inputs[INPUT_DOWN], sfJoystickY);
}

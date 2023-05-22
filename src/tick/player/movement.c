/*
** EPITECH PROJECT, 2022
** tick/player/movement.c
** File description:
** Manage player movement
*/

#include "calls.h"
#include "const.h"
#include "inputs.h"
#include "my.h"
#include "struct.h"
#include <stddef.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>

static int check_movement(int const player,
sfVector2f const position, char const *selected_points)
{
    sfVector2f points[6] = {{1, 6}, {3, 6}, {6, 6}, {1, 7}, {3, 7}, {6, 7}};
    sfVector2f pos_tmp = {0, 0};
    int returned = 0;

    for (int i = 0; i < 6 && i < LEN(selected_points); i++) {
        pos_tmp.x = position.x + points[i].x / TILE;
        pos_tmp.y = position.y + points[i].y / TILE;
        returned = HITBOX_CHAR_BLOCK + 1;
        if (selected_points[i] == '1')
            returned = map_check_collisions(GAME.map, pos_tmp.x, pos_tmp.y);
        if (returned == HITBOX_CHAR_BLOCK)
            return 0;
    }
    return 1;
}

static int move_player(int const player,
float const x, float const y, char const *selected_points)
{
    float speed = (float)PLAYER_SPEED * ((float)GAME.delta / SEC_TO_MICRO);
    float speed_tmp = 0;
    sfVector2f position = GAME.player[player].position;
    sfVector2f position_tmp = {0, 0};

    for (speed_tmp = speed; speed_tmp > 0; speed_tmp -= (float)1 / TILE) {
        position_tmp.x = position.x + x * speed_tmp;
        position_tmp.y = position.y + y * speed_tmp;
        if (!check_movement(player, position_tmp, selected_points))
            speed = speed_tmp - (float)1 / TILE;
    }
    if (!check_movement(player, position_tmp, selected_points))
        return 0;
    GAME.player[player].position.x = position.x + x * speed;
    GAME.player[player].position.y = position.y + y * speed;
    return 1;
}

static void move_from_inputs(int const player, float const *inputs)
{
    int moved = 0;

    if (inputs[INPUT_LEFT] > 0) {
        moved += move_player(player, 0 - inputs[INPUT_LEFT], 0, "100100");
        GAME.player[player].direction = 1;
    }
    if (inputs[INPUT_RIGHT] > 0) {
        moved += move_player(player, inputs[INPUT_RIGHT], 0, "001001");
        GAME.player[player].direction = 0;
    }
    if (inputs[INPUT_UP] > 0)
        moved += move_player(player, 0, 0 - inputs[INPUT_UP], "111000");
    if (inputs[INPUT_DOWN] > 0)
        moved += move_player(player, 0, inputs[INPUT_DOWN], "000111");
    if (moved != 0)
        tick_player_walk_animation(player);
    else
        GAME.player[player].deltawalking = 0;
}

static void update_player(int const player)
{
    float inputs[INPUT_TOTAL_SIZE];
    int temp_ints[2] = {0, 0};
    player_t *player_struct = &GAME.player[player];

    if (!player_struct->connected)
        return;
    for (int i = 0; i < INPUT_TOTAL_SIZE; i++)
        inputs[i] = MAX(player_struct->inputs.press[i], 1);
    tick_player_input_joysticks(player, inputs);
    move_from_inputs(player, inputs);
}

void tick_player_movement(void)
{
    if (GAME.map == NULL)
        return;
    if (!GAME.window_focus)
        return;
    for (int i = 0; i < PLAYER_MAX; i++)
        update_player(i);
}

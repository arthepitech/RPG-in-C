/*
** EPITECH PROJECT, 2022
** menu/update_key.c
** File description:
** Updates a menu for inputs etc.
*/

#include "calls.h"
#include "filepaths.h"
#include "inputs.h"
#include "menus.h"
#include "my.h"
#include "palettes.h"
#include "struct.h"
#include <stdlib.h>

static int valid_key(int const id, menu_button_t *menu_button,
sfBool const jystck)
{
    int player = menu_button->access;
    int controller = 0;

    if (!jystck && !sfKeyboard_isKeyPressed(id))
        return 0;
    if (jystck) {
        controller = MIN(GAME.player[player].inputs.input_type, 0);
        if (!sfJoystick_isButtonPressed(controller, id))
            return 0;
    }
    if (GAME.player[player].inputs.press[INPUT_INTERACT] > 1) {
        if (id == GAME.player[player].inputs.keys[INPUT_INTERACT] && !jystck)
            return 0;
        if (id == GAME.player[player].inputs.buttons[INPUT_INTERACT] && jystck)
            return 0;
    }
    return 1;
}

static int ask_input(menu_t *menu, int const id, sfBool const is_joystick,
int const input_type)
{
    int max = sfKeyCount;
    menu_button_t *button = menu->button[id];

    if (is_joystick)
        max = sfJoystickButtonCount;
    tick_poll_events();
    tick_deltaclock();
    tick_player_inputs();
    window_resize();
    sfRenderWindow_clear(GAME.window, sfWhite);
    tick_change_view(-1);
    menu_draw(menu);
    sfRenderWindow_display(GAME.window);
    for (int i = 0; i < max; i++)
        if (valid_key(i, button, is_joystick))
            return i;
    return -2;
}

static void ask_player(menu_t *menu, int const id, int const tag,
sfBool const is_joystick)
{
    menu_button_t *button = menu->button[id];
    int input = -2;
    int click = sfMouseRight;

    while (window_is_open() && input < -1 && !sfMouse_isButtonPressed(click))
        input = ask_input(menu, id, is_joystick, tag - 1);
    if (input < 0)
        input = -1;
    GAME.player[button->access].inputs.press[tag - 1] += 2;
    if (is_joystick)
        GAME.player[button->access].inputs.buttons[tag - 1] = input;
    else
        GAME.player[button->access].inputs.keys[tag - 1] = input;
}

void menu_update_key(menu_t *menu, int const id)
{
    menu_button_t *button = menu->button[id];
    int tag = button->tags[MENU_TAG_MATCHBUT];
    sfBool is_joystick = sfTrue;

    if (tag < 1 && button->tags[MENU_TAG_MATCHKEY] < 1)
        return;
    if (button->tags[MENU_TAG_MATCHKEY] >= 1) {
        is_joystick = sfFalse;
        tag = button->tags[MENU_TAG_MATCHKEY];
    }
    if (tag - 1 >= INPUT_TOTAL_SIZE)
        return;
    ask_player(menu, id, tag, is_joystick);
}

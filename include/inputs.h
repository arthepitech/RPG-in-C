/*
** EPITECH PROJECT, 2022
** inputs.h
** File description:
** Everything about keyboard and controllers
*/

#pragma once
    #define INPUT_TYPE_KEYBOARD (int)-1
    #define INPUT_JOYSTICK_MIN (float)1.0
    #define INPUT_JOYSTICK_MAX (float)20.0

enum joystick_buttons_incices {
    JB_B,
    JB_A,
    JB_Y,
    JB_X,
    JB_L,
    JB_R,
    JB_ZL,
    JB_ZR,
    JB_SELECT,
    JB_START,
    JB_LCLICK,
    JB_RCLICK,
    JB_HOME,
    JB_SCREENSHOT,
    JB_TOTAL_SIZE,
};

enum inputs_incices {
    INPUT_UP,
    INPUT_LEFT,
    INPUT_DOWN,
    INPUT_RIGHT,
    INPUT_INTERACT,
    INPUT_RETURN,
    INPUT_QUIT,
    INPUT_NOTE_LEFT,
    INPUT_NOTE_MIDDLE,
    INPUT_NOTE_RIGHT,
    INPUT_TOTAL_SIZE,
};

//
typedef struct inputs_s {
    int buttons[INPUT_TOTAL_SIZE];
    int keys[INPUT_TOTAL_SIZE];
    int input_type;
    int press[INPUT_TOTAL_SIZE];
} inputs_t;

void inputs_load(char const *name);
//Returns 1 if a player if found
//Otherwise, returns 0
int inputs_new_controller(int const id);
void inputs_save(char const *name);
void inputs_update(void);

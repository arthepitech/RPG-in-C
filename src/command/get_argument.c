/*
** EPITECH PROJECT, 2022
** command/get_argument.c
** File description:
** Convert an argument into informations
*/

#include "event.h"
#include "my.h"
#include "script.h"
#include "struct.h"
#include <stdlib.h>

static int get_variable_id(char const *str)
{
    int variable = 0;

    if (str == NULL || str[0] == '\0')
        return 0;
    for (int i = 1; str[i] != '\0'; i++) {
        if (ISD(str[i])) {
            variable *= 10;
            variable += CTI(str[i]);
        }
    }
    return variable;
}

static int is_char_in_str(char const c, char const *str)
{
    if (str == NULL)
        return 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (c == str[i])
            return 1;
    return 0;
}

static int get_saved_variable(int const var_id)
{
    if (var_id < 0 || SAVED_VARIABLES <= var_id)
        return 0;
    return GAME.saved_variables[var_id];
}

float command_get_argument(char const *arg, event_t const *event)
{
    if (arg == NULL)
        return 0;
    if (event == NULL)
        return my_str_to_double(arg);
    if (is_char_in_str(arg[0], CMD_VAR_CHARACTERS))
        return event_variable_get(event, get_variable_id(arg));
    if (is_char_in_str(arg[0], CMD_VAR_SAVED_CHARACTERS))
        return get_saved_variable(get_variable_id(arg));
    return my_str_to_double(arg);
}

/*
** EPITECH PROJECT, 2022
** command/destroy.c
** File description:
** Destroys a command
*/

#include "my.h"
#include "script.h"
#include <stdlib.h>

void command_destroy(command_t command)
{
    if (command.ary != NULL)
        my_free_char_2d(command.ary);
}

/*
** EPITECH PROJECT, 2022
** command/execute/print.c
** File description:
** Displays the arguments
*/

#include "event.h"
#include "my.h"
#include "script.h"
#include <stdlib.h>

static void print_argument(char const *arg)
{
    my_putstr(arg);
    my_putchar(' ');
}

int command_execute_print(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 2)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    for (int i = 1; command.ary[i] != NULL; i++)
        print_argument(command.ary[i]);
    my_putchar(LINEBREAK);
    return 1;
}

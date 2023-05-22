/*
** EPITECH PROJECT, 2022
** command/execute/open_menu.c
** File description:
** Opens a new menu
*/

#include "event.h"
#include "menus.h"
#include "my.h"
#include "script.h"
#include <stdlib.h>

int command_execute_open_menu(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 2)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 2)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    menu_open(command.ary[1]);
    return 1;
}

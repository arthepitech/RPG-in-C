/*
** EPITECH PROJECT, 2022
** command/execute/start_battle.c
** File description:
** Tulululululululu Tudutududutududududu TUdududuDutudududuDU
*/

#include "battles.h"
#include "my.h"
#include "script.h"
#include "struct.h"
#include <stdlib.h>

int command_execute_start_battle(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 2)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 2)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    return battle_start(command.ary[1]);
}

/*
** EPITECH PROJECT, 2022
** command/execute/play_bgm.c
** File description:
** Plays a music
*/

#include "event.h"
#include "my.h"
#include "script.h"
#include "sound.h"
#include <stdlib.h>

int command_execute_play_bgm(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 2)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 2)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    bgm_play(command.ary[1]);
    return 1;
}

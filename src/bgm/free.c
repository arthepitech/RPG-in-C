/*
** EPITECH PROJECT, 2022
** bgm/free.c
** File description:
** Initialise the bgm struct
*/

#include "sound.h"
#include "struct.h"
#include <stdlib.h>

void bgm_free(void)
{
    if (GAME.bgm.clock != NULL)
        sfClock_destroy(GAME.bgm.clock);
    if (GAME.bgm.music != NULL)
        sfMusic_destroy(GAME.bgm.music);
    if (GAME.bgm.name != NULL)
        free(GAME.bgm.name);
    GAME.bgm.clock = NULL;
    GAME.bgm.music = NULL;
    GAME.bgm.name = NULL;
}

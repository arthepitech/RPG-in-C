/*
** EPITECH PROJECT, 2022
** bgm/initialise.c
** File description:
** Initialise the bgm struct
*/

#include "struct.h"
#include <stdlib.h>

void bgm_initialise(void)
{
    GAME.bgm.clock = NULL;
    GAME.bgm.music = NULL;
    GAME.bgm.name = NULL;
}

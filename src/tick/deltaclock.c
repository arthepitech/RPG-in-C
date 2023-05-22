/*
** EPITECH PROJECT, 2022
** tick/deltaclock.c
** File description:
** Updates GAME.delta
*/

#include "struct.h"
#include <stddef.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>

int tick_deltaclock(void)
{
    sfTime delatime = sfClock_restart(GAME.deltaclock);

    if (GAME.deltaclock == NULL)
        return 0;
    GAME.delta = sfTime_asMicroseconds(delatime);
    sfClock_restart(GAME.deltaclock);
    return 1;
}

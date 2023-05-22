/*
** EPITECH PROJECT, 2022
** battle/notes/pressed/wrong.c
** File description:
** Displays every note on screen
*/

#include "battles.h"
#include <stdlib.h>

void battle_notes_press_wrong(battle_t *battle, int const input, sfBool missed)
{
    if (battle == NULL)
        return;
    battle->damage[DAMAGE_CRIT] = 0;
    if (!missed)
        battle->note_accuracy -= (double)1 / battle->note_total;
}

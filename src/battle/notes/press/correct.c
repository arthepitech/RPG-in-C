/*
** EPITECH PROJECT, 2022
** battle/notes/pressed/correct.c
** File description:
** Displays every note on screen
*/

#include "battles.h"
#include "my.h"
#include <stdlib.h>

static void play_note(battle_t *battle, int const player, note_t *note)
{
    if (battle->note_sound[player][note->type] == NULL)
        return;
    sfSound_setPitch(battle->note_sound[player][note->type], note->pitch);
    sfSound_play(battle->note_sound[player][note->type]);
}

void battle_notes_press_correct(battle_t *battle, int const plyr, note_t *note)
{
    int range = (NOTE_RANGE / NOTE_SPEED) * SEC_TO_MICRO;
    double precision = 0;

    if (battle == NULL || note == NULL)
        return;
    play_note(battle, plyr, note);
    precision = 100 - (double)(ABS(note->timing) * 100) / range, 100;
    if (precision <= 0)
        return;
    battle->note_accuracy += (precision / battle->note_total) / 100;
}

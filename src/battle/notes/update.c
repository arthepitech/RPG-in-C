/*
** EPITECH PROJECT, 2022
** battle/notes/udpate.c
** File description:
** Updates every note of the battle
*/

#include "battles.h"
#include "const.h"
#include "items.h"
#include "my.h"
#include "struct.h"
#include "tiles.h"
#include <stdlib.h>
#include <SFML/Audio.h>

static void remove_note(battle_t *battle, int const player, int const id)
{
    if (battle->note == NULL)
        return;
    for (int i = 0; i <= id; i++)
        if (battle->note[player][id] == NULL)
            return;
    free(battle->note[player][id]);
    battle->note[player][id] = NULL;
    for (int i = id; battle->note[player][i + 1] != NULL; i++) {
        battle->note[player][i] = battle->note[player][i + 1];
        battle->note[player][i + 1] = NULL;
    }
}

static int update_single(battle_t *battle, int const player, int const id,
int const played)
{
    note_t *note = battle->note[player][id];
    int range = (NOTE_RANGE / NOTE_SPEED) * SEC_TO_MICRO;
    int press = GAME.player[player].inputs.press[BATTLE_INPUTS[note->type]];
    int accuracy = 0;

    note->timing -= GAME.delta;
    if (note->timing > 0 + range)
        return 0;
    if (note->timing < 0 - range) {
        battle_notes_press_wrong(battle, note->type, sfTrue);
        remove_note(battle, player, id);
        return 1;
    }
    if (press == 1 && played <= 0) {
        battle_notes_press_correct(battle, player, note);
        remove_note(battle, player, id);
        return 1;
    }
    return 0;
}

static void update_player(battle_t *battle, int const player)
{
    int note_type = 0;
    int notes_played[NOTE_TOTAL_SIZE] = {0, 0, 0};
    int played = 0;
    int press = 0;

    if (battle->note[player] == NULL || battle->note[player][0] == NULL)
        return;
    for (int i = 0; battle->note[player][i] != NULL; i++) {
        note_type = battle->note[player][i]->type;
        played = update_single(battle, player, i, notes_played[note_type]);
        notes_played[note_type] += played;
        if (played > 0)
            i--;
    }
    for (int i = 0; i < NOTE_TOTAL_SIZE; i++) {
        press = GAME.player[player].inputs.press[BATTLE_INPUTS[i]];
        if (press == 1 && notes_played[i] <= 0)
            battle_notes_press_wrong(battle, i, sfFalse);
    }
}

void battle_notes_update(battle_t *battle)
{
    for (int i = 0; i < PLAYER_MAX; i++)
        update_player(battle, i);
}

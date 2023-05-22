/*
** EPITECH PROJECT, 2022
** battle/song/get.c
** File description:
** Searchs an song in files
*/

#include "battles.h"
#include "filepaths.h"
#include "my.h"
#include <stdlib.h>

static void extract_line(battle_t *battle, note_t **notes, char const *str,
int *tempo)
{
    int length = 0;
    char **ary = my_str_to_array(str, SONG_SEPARATORS);

    if (ary == NULL)
        return;
    for (length = 0; ary[length] != NULL; length++);
    if (my_strcmp(ary[0], SONG_TEMPO)) {
        if (length > 1)
            *tempo = my_str_to_int(ary[1]);
        return;
    }
    if (length < 2 || my_strcmp(ary[0], SONG_BAR_LINE))
        return;
    if (!(ISD(ary[0][0]) || ary[0][0] == '-') && battle != NULL)
        for (int i = 1; i < length && (i - 1) < DAMAGE_TOTAL_SIZE; i++)
            battle->damage[i - 1] = my_str_to_double(ary[i]);
    if (ISD(ary[0][0]) || ary[0][0] == '-')
        battle_song_add_note(notes, ary, *tempo);
    if (ISD(ary[0][0]) || ary[0][0] == '-' && battle != NULL)
        battle->note_total += 1;
}

static void remove_note(note_t **notes, int const id)
{
    if (notes == NULL)
        return;
    for (int i = 0; i <= id; i++)
        if (notes[id] == NULL)
            return;
    free(notes[id]);
    notes[id] = NULL;
    for (int i = id; notes[i + 1] != NULL; i++) {
        notes[i] = notes[i + 1];
        notes[i + 1] = NULL;
    }
}

static void extract_infos(battle_t *battle, note_t **notes, char * const *ary)
{
    int tempo = TEMPO_DEFAULT;

    for (int i = 0; ary[i] != NULL; i++)
        extract_line(battle, notes, ary[i], &tempo);
    for (int i = 0; notes[i] != NULL; i++) {
        if (notes[i]->type < 0) {
            remove_note(notes, i);
            i--;
        }
    }
}

static int count_notes(char * const *ary)
{
    int count = 0;

    if (ary == NULL)
        return 0;
    for (int i = 0; ary[i] != NULL; i++)
        if (ISD(ary[i][0]) || ary[i][0] == '-')
            count++;
    return count;
}

note_t **battle_song_get(battle_t *battle, char const *name)
{
    note_t **notes = NULL;
    char **ary = NULL;
    int count = 0;

    ary = path_form_and_convert(name, PATH_MUSICS);
    if (ary == NULL)
        return NULL;
    count = count_notes(ary);
    notes = malloc(sizeof(note_t *) * (count + 1));
    if (notes == NULL) {
        my_free_char_2d(ary);
        return NULL;
    }
    for (int i = 0; i < (count + 1); i++)
        notes[i] = NULL;
    extract_infos(battle, notes, ary);
    my_free_char_2d(ary);
    return notes;
}

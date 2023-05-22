/*
** EPITECH PROJECT, 2022
** battle/song/add_note.c
** File description:
** Adds a note to a song
*/

#include "const.h"
#include "battles.h"
#include "filepaths.h"
#include "my.h"
#include <stdlib.h>

static void add_note(note_t **notes, note_t *new_note)
{
    int id = 0;

    for (id = 0; notes[id] != NULL; id++);
    notes[id] = new_note;
    if (id <= 0)
        return;
    new_note->timing = notes[id - 1]->duration * (float)SEC_TO_MICRO;
    new_note->timing /= ((float)notes[id - 1]->tempo / MIN_TO_SEC);
    new_note->timing += notes[id - 1]->timing;
}

static int try_pitch(char const *note, char const *str, float *pitch)
{
    char **ary = NULL;
    int length = 0;

    if (note == NULL || str == NULL)
        return 0;
    ary = my_str_to_array(str, SONG_SEPARATORS);
    if (ary == NULL)
        return 0;
    for (length = 0; ary[length] != NULL; length++);
    if (length < 2 || !my_strcmp(note, ary[0])) {
        my_free_char_2d(ary);
        return 0;
    }
    *pitch = my_str_to_double(ary[1]);
    my_free_char_2d(ary);
    return 1;
}

static float get_pitch(char const *note)
{
    float pitch = 1;
    char **ary = path_form_and_convert(FILE_NOTES_TXT, PATH_MISC);

    if (ary == NULL)
        return pitch;
    for (int i = 0; ary[i] != NULL; i++) {
        if (try_pitch(note, ary[i], &pitch)) {
            my_free_char_2d(ary);
            return pitch;
        }
    }
    my_free_char_2d(ary);
    return pitch;
}

static void extract_info(note_t *note, char * const *ary, int const tempo)
{
    int length = 0;

    note->duration = 0;
    note->pitch = 1;
    note->tempo = TEMPO_DEFAULT;
    note->timing = NOTE_WAIT * SEC_TO_MICRO;
    note->type = 0;
    for (length = 0; ary[length] != NULL; length++);
    if (length >= 1)
        note->type = my_str_to_int(ary[0]) - 1;
    if (length >= 2)
        note->duration = my_str_to_double(ary[1]);
    if (length >= 3)
        note->pitch = get_pitch(ary[2]);
}

void battle_song_add_note(note_t **notes, char * const *ary, int const tempo)
{
    note_t *new_note = NULL;

    if (ary == NULL || notes == NULL)
        return;
    new_note = malloc(sizeof(note_t));
    if (new_note == NULL)
        return;
    extract_info(new_note, ary, tempo);
    new_note->tempo = tempo;
    if (new_note->type >= NOTE_TOTAL_SIZE)
        free(new_note);
    else
        add_note(notes, new_note);
}

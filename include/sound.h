/*
** EPITECH PROJECT, 2022
** bgm.h
** File description:
** Function calls
*/

#pragma once
    #include <SFML/Audio.h>
    #include <SFML/System/Clock.h>

typedef struct sound_s {
    sfClock *clock;
    sfSound *sound;
    sfSoundBuffer *buffer;
} sound_t;

typedef struct music_s {
    sfClock *clock;
    sfMusic *music;
    char *name;
} music_t;

static const float BGM_DEFAULT_VOLUME = 15;
static const float BGM_BATTLE_VOLUME = 3;

void bgm_free(void);
void bgm_initialise(void);
void bgm_play(char const *name);

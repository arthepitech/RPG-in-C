/*
** EPITECH PROJECT, 2022
** bgm/play.c
** File description:
** Initialise the bgm struct
*/

#include "filepaths.h"
#include "files.h"
#include "my.h"
#include "sound.h"
#include "struct.h"
#include <stdlib.h>

static void destroy_previous(void)
{
    bgm_free();
    GAME.bgm.clock = NULL;
    GAME.bgm.music = NULL;
    GAME.bgm.name = NULL;
}

static void play_bgm_music(sfMusic *music)
{
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, BGM_DEFAULT_VOLUME);
    sfMusic_play(music);
}

static int invalid_path(char *path)
{
    if (path == NULL)
        return 1;
    if (file_exists(path))
        return 0;
    free(path);
    return 1;
}

void bgm_play(char const *name)
{
    char *path = NULL;

    if (GAME.bgm.name != NULL && my_strcmp(GAME.bgm.name, name))
        return;
    path = path_form(name, PATH_BGM);
    if (invalid_path(path))
        return;
    destroy_previous();
    GAME.bgm.music = sfMusic_createFromFile(path);
    free(path);
    if (GAME.bgm.music == NULL)
        return;
    play_bgm_music(GAME.bgm.music);
    if (GAME.bgm.name != NULL)
        free(GAME.bgm.name);
    GAME.bgm.name = DUP(name);
}

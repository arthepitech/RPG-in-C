/*
** EPITECH PROJECT, 2022
** tick/map_change.c
** File description:
** Updates GAME.delta
*/

#include "calls.h"
#include "filepaths.h"
#include "struct.h"
#include "maps.h"
#include "my.h"
#include "script.h"
#include <stddef.h>

static void change_position(void)
{
    if (GAME.map_next_position.x < 0 || GAME.map_next_position.y < 0)
        return;
    for (int i = 0; i < PLAYER_MAX; i++) {
        if (GAME.player[i].position.x >= 0)
            GAME.player[i].position.x = GAME.map_next_position.x;
        if (GAME.player[i].position.x >= 0)
            GAME.player[i].position.y = GAME.map_next_position.y;
    }
}

static void change_map(char const *name)
{
    map_t *old_map = GAME.map;

    if (name == NULL)
        return;
    GAME.map = map_get(name);
    if (GAME.map == NULL) {
        GAME.map = old_map;
        return;
    }
    if (old_map != NULL)
        map_destroy(old_map);
    script_call(SCRIPT_SYSTEM_LOAD_MAP, NULL);
    change_position();
}

int tick_map_change(void)
{
    if (GAME.map_next == NULL)
        return 0;
    if (my_strcmp(GAME.map_next, MAP_EXIT)) {
        if (GAME.map != NULL)
            save_save(FILE_SAVE);
        free(GAME.map_next);
        free(GAME.map);
        GAME.map = NULL;
        GAME.map_next = NULL;
        GAME.map_next_position.x = -1;
        GAME.map_next_position.y = -1;
        return 1;
    }
    change_map(GAME.map_next);
    free(GAME.map_next);
    GAME.map_next = NULL;
    GAME.map_next_position.x = -1;
    GAME.map_next_position.y = -1;
    return 1;
}

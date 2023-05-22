/*
** EPITECH PROJECT, 2022
** command/execute/save_new.c
** File description:
** Displays the arguments
*/

#include "calls.h"
#include "const.h"
#include "my.h"
#include "script.h"
#include "struct.h"
#include <stdlib.h>

static void free_inventory(int const id)
{
    if (GAME.inventory[id] == NULL)
        return;
    for (int i = 0; GAME.inventory[id][i] != NULL; i++)
        free(GAME.inventory[id][i]);
    free(GAME.inventory[id]);
    GAME.inventory[id] = NULL;
}

static void initialise_player(player_t *player)
{
    for (int i = 0; i < ITEM_TYPE_TOTAL_SIZE; i++)
        if (player->equipment[i] != NULL) {
            item_destroy(player->equipment[i]);
            player->equipment[i] = NULL;
        }
    player->connected = 0;
    player->deltawalking = 0;
    player->direction = 0;
    player->position.x = 0;
    player->position.y = 0;
    player->skin_tone = sfWhite;
    player->skin_tone_id = 0;
}

static void save_new(void)
{
    if (GAME.score != NULL) {
        for (int i = 0; GAME.score[i] != NULL; i++)
            free(GAME.score[i]);
        free(GAME.score);
        GAME.score = NULL;
    }
    for (int i = 0; i < PLAYER_MAX; i++)
        initialise_player(&GAME.player[i]);
    for (int i = 0; i < ITEM_TYPE_TOTAL_SIZE; i++)
        free_inventory(i);
    if (GAME.map_next == NULL)
        free(GAME.map_next);
    GAME.map_next = DUP(MAP_EXIT);
    for (int i = 0; i < SAVED_VARIABLES; i++)
        GAME.saved_variables[i] = SAVED_VARIABLES_DEFAULT;
}

int command_execute_save_new(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 1)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    if (command.length > 1)
        return command_display_error(command.ary[0], ER_CMD_TOOMANY);
    save_new();
    return 1;
}

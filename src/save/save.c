/*
** EPITECH PROJECT, 2022
** save/save.c
** File description:
** Saves the... save
*/

#include "calls.h"
#include "files.h"
#include "filepaths.h"
#include "my.h"
#include "struct.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

static void player_stuff(int const fd, int const player)
{
    save_write_double(fd, GAME.player[player].position.x, 4);
    write(fd, " ", 1);
    save_write_double(fd, GAME.player[player].position.y, 4);
    write(fd, " ", 1);
    save_write_value(fd, GAME.player[player].skin_tone_id);
    write(fd, " ", 1);
    for (int i = 0; i < ITEM_TYPE_TOTAL_SIZE; i++) {
        if (GAME.player[player].equipment[i] == NULL)
            save_write_str(fd, SAVE_NOTHING);
        else
            save_write_str(fd, GAME.player[player].equipment[i]->file);
    }
    write(fd, "\n", 1);
}

static void write_inventories(int const fd)
{
    for (int i = 0; i < SAVED_VARIABLES; i++) {
        save_write_value(fd, GAME.saved_variables[i]);
        write(fd, " ", 1);
    }
    write(fd, "\n", 1);
    for (int i = 0; i < ITEM_TYPE_TOTAL_SIZE; i++)
        save_write_ary(fd, GAME.inventory[i]);
    write(fd, "\n", 1);
    save_write_ary(fd, GAME.score);
    write(fd, "\n", 1);
}

static void write_file(char const *path)
{
    int fd = 0;

    fd = open(path, O_WRONLY);
    if (fd <= 0)
        return;
    write_inventories(fd);
    if (GAME.map == NULL)
        save_write_str(fd, NULL);
    else
        save_write_str(fd, GAME.map->file);
    write(fd, "\n", 1);
    for (int i = 0; i < PLAYER_MAX; i++)
        player_stuff(fd, i);
    write(fd, "\n", 1);
}

static int create_file_if_needed(char const *path)
{
    FILE *f_fd = NULL;

    f_fd = fopen(path, "w");
    if (f_fd == NULL && !file_exists(path))
        return 0;
    if (file_exists(path)) {
        fclose(f_fd);
        return 1;
    }
    fclose(f_fd);
    return 1;
}

void save_save(char const *name)
{
    FILE *f_fd = NULL;
    char *path = NULL;

    if (name == NULL)
        return;
    path = path_form(name, PATH_SAVED);
    if (path == NULL)
        return;
    if (!create_file_if_needed(path)) {
        free(path);
        return;
    }
    write_file(path);
}

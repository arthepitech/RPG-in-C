/*
** EPITECH PROJECT, 2022
** inputs/save.c
** File description:
** Saves the input file
*/

#include "files.h"
#include "filepaths.h"
#include "inputs.h"
#include "my.h"
#include "struct.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

static void write_value(int const fd, int value)
{
    char c = (ABS(value) % 10) + '0';

    if (value == 0) {
        write(fd, "0", 1);
        return;
    }
    if (value < 0) {
        write(fd, "-", 1);
        value *= -1;
    }
    if (value / 10 != 0)
        write_value(fd, value / 10);
    write(fd, &c, 1);
}

static void write_inputs(int const fd, int const *inputs)
{
    for (int i = 0; i < INPUT_TOTAL_SIZE; i++) {
        write_value(fd, inputs[i]);
        write(fd, " ", 1);
    }
    write(fd, "\n", 1);
}

static void write_file(char const *path)
{
    int fd = 0;

    fd = open(path, O_WRONLY);
    if (fd <= 0)
        return;
    for (int i = 0; i < PLAYER_MAX; i++) {
        write_inputs(fd, GAME.player[i].inputs.keys);
        write_inputs(fd, GAME.player[i].inputs.buttons);
    }
}

static int create_file_if_needed(char const *path)
{
    FILE *f_fd = NULL;

    if (file_exists(path))
        return 1;
    f_fd = fopen(path, "w");
    if (f_fd == NULL)
        return 0;
    fclose(f_fd);
    return 1;
}

void inputs_save(char const *name)
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

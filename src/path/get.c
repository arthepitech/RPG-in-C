/*
** EPITECH PROJECT, 2022
** path/get.c
** File description:
** Gets a filepath from PATHS_TXT
*/

#include "files.h"
#include "my.h"
#include "filepaths.h"
#include <stddef.h>
#include <stdlib.h>

static char *free_ary(char **ary)
{
    if (ary == NULL)
        return NULL;
    for (int i = 0; ary[i] != NULL; i++)
        free(ary[i]);
    free(ary);
    return NULL;
}

static int get_ary_length(char **ary)
{
    int length = 0;

    if (ary == NULL)
        return -1;
    for (length = 0; ary[length] != NULL; length++);
    return length;
}

static char *search_in_string(int const path_asked, char *file)
{
    char **ary = NULL;

    ary = my_str_to_array(file, "\n");
    free(file);
    if (ary == NULL)
        return NULL;
    if (path_asked >= get_ary_length(ary))
        return free_ary(ary);
    file = my_strdup(ary[path_asked]);
    return file;
}

char *path_get(int const path_asked)
{
    char *file = NULL;

    file = file_read(PATHS_TXT);
    if (file == NULL)
        return NULL;
    file = search_in_string(path_asked, file);
    return file;
}

/*
** EPITECH PROJECT, 2022
** path/form.c
** File description:
** Constitute a filepath from name
*/

#include "filepaths.h"
#include "my.h"
#include <stddef.h>
#include <stdlib.h>

static char *get_name(char const *name, int const path_asked)
{
    char *name_with_ext = NULL;

    if (PATH_EXTENTIONS[path_asked] == NULL)
        return NULL;
    if (name == NULL)
        return NULL;
    name_with_ext = my_strcat(name, PATH_EXTENTIONS[path_asked]);
    if (name_with_ext == NULL)
        return NULL;
    return name_with_ext;
}

static char *get_path(int const path_asked)
{
    char *path = NULL;
    char *filepath = NULL;

    path = path_get(path_asked);
    if (path == NULL)
        return NULL;
    filepath = my_strcat(path, "/");
    free(path);
    if (filepath == NULL)
        return NULL;
    return filepath;
}

char *path_form(char const *name, int const path_asked)
{
    char *path = NULL;
    char *filename = NULL;
    char *filepath = NULL;

    if (path_asked >= PATH_TOTAL_SIZE)
        return NULL;
    filename = get_name(name, path_asked);
    if (filename == NULL)
        return NULL;
    path = get_path(path_asked);
    if (path == NULL) {
        free(filename);
        return NULL;
    }
    filepath = my_strcat(path, filename);
    free(filename);
    free(path);
    return filepath;
}

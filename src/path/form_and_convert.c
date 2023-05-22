/*
** EPITECH PROJECT, 2022
** path/form_and_convert.c
** File description:
** Constitute a filepath from name
*/

#include "filepaths.h"
#include "files.h"
#include "my.h"
#include <stddef.h>
#include <stdlib.h>

static char *file_get(char const *name, int const path_asked)
{
    char *path = NULL;
    char *file = NULL;

    path = path_form(name, path_asked);
    if (path == NULL)
        return NULL;
    file = file_read(path);
    free(path);
    return file;
}

char **path_form_and_convert(char const *name, int const path_asked)
{
    char *file = NULL;
    char **ary = NULL;

    if (name == NULL)
        return NULL;
    file = file_get(name, path_asked);
    if (file == NULL)
        return NULL;
    ary = my_str_to_array(file, "\n");
    free(file);
    if (ary == NULL)
        return NULL;
    return ary;
}

/*
** EPITECH PROJECT, 2021
** file/read.c
** File description:
** I teaching this file how to read
*/

#include "const.h"
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static char *copy_and_return(char *file)
{
    int i = 0;
    int length = LEN(file);
    char *copied_file = NULL;

    copied_file = malloc(sizeof(char) * (length + 1));
    for (i = 0; file[i] != '\0'; i++)
        copied_file[i] = file[i];
    copied_file[i] = '\0';
    free(file);
    return copied_file;
}

char *file_read(char const *path)
{
    int fd = 0;
    char *file = NULL;

    if (path == NULL)
        return NULL;
    fd = open(path, O_RDONLY);
    if (fd <= 0)
        return NULL;
    file = malloc(sizeof(char) * (FILE_BUFFER_SIZE + 1));
    if (file == NULL) {
        close(fd);
        return NULL;
    }
    for (int i = 0; i < FILE_BUFFER_SIZE + 1; i++)
        file[i] = '\0';
    read(fd, file, FILE_BUFFER_SIZE);
    close(fd);
    return copy_and_return(file);
}

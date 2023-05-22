/*
** EPITECH PROJECT, 2022
** file/write.c
** File description:
** Writes a file
*/

#include "const.h"
#include "my.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

static int write_in(int const fd, char const *str)
{
    int length = LEN(str);
    char *file = NULL;

    file = malloc(sizeof(char) * (length + 1));
    if (file == NULL) {
        close(fd);
        return 0;
    }
    for (int i = 0; i < length + 1; i++)
        file[i] = '\0';
    read(fd, file, length);
    write(fd, str, length);
    close(fd);
    free(file);
    return 1;
}

int file_write(char const *path, char const *str)
{
    int fd = 0;
    FILE *f_fd = NULL;
    char *file = NULL;
    int length = LEN(str);

    if (path == NULL || str == NULL)
        return 0;
    f_fd = fopen(path, "w");
    if (f_fd == NULL)
        return 0;
    fclose(f_fd);
    fd = open(path, O_WRONLY);
    if (fd <= 0)
        return 0;
    return write_in(fd, str);
}

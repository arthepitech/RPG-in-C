/*
** EPITECH PROJECT, 2021
** file/exists.c
** File description:
** if a file exists
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int file_exists(char const *path)
{
    int fd = 0;

    fd = open(path, O_RDONLY);
    if (fd <= 0)
        return 0;
    close(fd);
    return 1;
}

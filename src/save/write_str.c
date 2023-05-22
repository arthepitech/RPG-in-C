/*
** EPITECH PROJECT, 2022
** save/write_str.c
** File description:
** Saves the... save
*/

#include "calls.h"
#include "my.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

void save_write_str(int const fd, char const *str)
{
    if (str == NULL) {
        save_write_str(fd, SAVE_NOTHING);
        return;
    }
    for (int i = 0; str[i] != '\0'; i++)
        write(fd, &(str[i]), 1);
    write(fd, " ", 1);
}

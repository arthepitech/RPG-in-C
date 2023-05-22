/*
** EPITECH PROJECT, 2022
** save/write_ary.c
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

void save_write_ary(int const fd, char * const *ary)
{
    if (ary == NULL) {
        save_write_str(fd, SAVE_NOTHING);
        return;
    }
    for (int i = 0; ary[i] != NULL; i++) {
        for (int j = 0; ary[i][j] != '\0'; j++)
            write(fd, &(ary[i][j]), 1);
        write(fd, " ", 1);
    }
}

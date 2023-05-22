/*
** EPITECH PROJECT, 2022
** save/write_value.c
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

void save_write_value(int const fd, int value)
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
        save_write_value(fd, value / 10);
    write(fd, &c, 1);
}

void save_write_double(int const fd, float value, int const precision)
{
    int e10 = 1;
    long int nb2 = 0;

    for (int i = 0; i < precision; i++)
        e10 *= 10;
    nb2 = value * e10;
    save_write_value(fd, nb2 / e10);
    write(fd, ".", 1);
    save_write_value(fd, nb2 % e10);
}

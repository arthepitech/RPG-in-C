/*
** EPITECH PROJECT, 2022
** files.h
** File description:
** Things about files
*/

#pragma once
int file_exists(char const *path);
char *file_read(char const *path);
int file_write(char const *path, char const *str);

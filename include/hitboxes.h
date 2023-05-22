/*
** EPITECH PROJECT, 2022
** hitboxes.h
** File description:
** Hitboxes used to compute collisions
*/

#pragma once
    #define HITBOX_DEFAULT_VALUE -1
    #define HITBOX_CHAR_NULL -1
    #define HITBOX_CHAR_BLOCK 0
    #define HITBOX_CHAR_PASS 1

    #include "const.h"

//Contains an array of TILE*TILE ints
typedef struct hitbox_s {
    int ary[TILE][TILE];
} hitbox_t;

static const char HITBOX_CHAR[] = {'@', 'O', 0};

//Returns NULL if a problem is encountered
hitbox_t *hitbox_create(void);
//Returns NULL
hitbox_t *hitbox_destroy(hitbox_t *hitbox);
//Returns NULL if a problem is encountered
hitbox_t *hitbox_get(char const *name);

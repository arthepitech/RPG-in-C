/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "calls.h"
#include "const.h"
#include "struct.h"

game_t GAME;

int main(int const ac, char * const *av, char * const *env)
{
    if (env == NULL || env[0] == NULL)
        return ERROR;
    return start();
}

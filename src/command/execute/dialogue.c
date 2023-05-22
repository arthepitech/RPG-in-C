/*
** EPITECH PROJECT, 2022
** command/execute/dialogue.c
** File description:
** Displays the arguments
*/

#include "event.h"
#include "menus.h"
#include "my.h"
#include "script.h"
#include <stdlib.h>

static void modify_menu(char * const *ary, menu_t *menu)
{
    int length = 0;
    int buttons = 0;

    if (menu->button == NULL)
        return;
    if (menu->window == NULL || menu->window[0] == NULL)
        return;
    for (length; ary[length] != NULL; length++);
    for (buttons; menu->button[buttons] != NULL; buttons++);
    for (int i = 0; i < length - 1 && i < buttons; i++) {
        menu->window[0]->size.y += 1;
        menu->window[0]->position.y -= 0.5;
        if (menu->button[i]->text != NULL)
            free(menu->button[i]->text);
        menu->button[i]->text = DUP(ary[i + 1]);
    }
    for (int i = 0; menu->button[i] != NULL; i++)
        menu->button[i]->position.y = menu->window[0]->position.y + i + 1;
}

static int dialogue(char * const *ary)
{
    menu_t *menu = NULL;

    if (ary == NULL)
        return 0;
    menu = menu_get(FILE_DIALOGUE);
    if (menu == NULL)
        return 0;
    modify_menu(ary, menu);
    menu_open_loop(menu);
    menu_destroy(menu);
    return 1;
}

int command_execute_dialogue(command_t command, event_t *event)
{
    if (command.ary == NULL || command.length < 1)
        return 0;
    if (command.length < 2)
        return command_display_error(command.ary[0], ER_CMD_TOOFEW);
    return dialogue(command.ary);
}

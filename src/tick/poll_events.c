/*
** EPITECH PROJECT, 2022
** tick/poll_events.c
** File description:
** Updates different things from sfml's events
*/

#include "struct.h"
#include <stddef.h>
#include <SFML/Graphics/RenderWindow.h>

static int poll_single_event(sfEvent *event)
{
    if (event == NULL)
        return 0;
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(GAME.window);
    if (event->type == sfEvtGainedFocus)
        GAME.window_focus = sfTrue;
    if (event->type == sfEvtLostFocus)
        GAME.window_focus = sfFalse;
    return 1;
}

int tick_poll_events(void)
{
    sfEvent event;
    int returned = 0;

    if (sfKeyboard_isKeyPressed(sfKeyEscape) && GAME.window_focus)
        sfRenderWindow_close(GAME.window);
    if (GAME.window_force_close)
        sfRenderWindow_close(GAME.window);
    while (sfRenderWindow_pollEvent(GAME.window, &event))
        returned += poll_single_event(&event);
    return returned;
}

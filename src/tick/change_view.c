/*
** EPITECH PROJECT, 2022
** tick/change_view.c
** File description:
** Updates GAME.delta
*/

#include "struct.h"
#include <stddef.h>
#include <SFML/Graphics/View.h>

static sfVector2i get_display_infos(int const player)
{
    sfVector2i result = {0, 0};

    if (player < 0) {
        result.x = 0;
        result.y = 1;
        return result;
    }
    for (int i = 0; i < PLAYER_MAX; i++) {
        if (GAME.player[i].connected && i == player)
            result.x = result.y;
        if (GAME.player[i].connected)
            result.y += 1;
    }
    return result;
}

static void compute_width_and_height(sfFloatRect *rect, sfVector2f *size,
sfVector2f *center, int const player)
{
    sfVector2i players = get_display_infos(player);
    sfVector2f ratio = window_get_size_ratio();
    sfVector2f temp_calc = {0, 0};
    sfVector2i screen = SCREEN_RESOLUTION;

    rect->left += (1 - rect->width) / 2;
    rect->top += (1 - rect->height) / 2;
    if (players.y < 2)
        return;
    temp_calc.x = ratio.x * ((float)(SPLITSCREEN_WIDTH / 2) / screen.x);
    temp_calc.y = ratio.y * ((float)(SPLITSCREEN_WIDTH / 2) / screen.y);
    rect->left += (rect->width / 2 + temp_calc.x) * (-1 + (players.x % 2) * 2);
    size->x -= 1;
    center->x -= (float)1 / 2;
    if (players.y < 3 || (players.y < 4 && players.x % 2 != 0))
        return;
    rect->top += (rect->height / 2 + temp_calc.y) * (-1 + (players.x / 2) * 2);
    size->y -= 1;
    center->y -= (float)1 / 2;
}

static void set_mouse_position(sfView const *view)
{
    sfVector2i pxl = sfMouse_getPositionRenderWindow(GAME.window);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(GAME.window, pxl, view);

    GAME.mouse_position.x = pos.x;
    GAME.mouse_position.y = pos.y;
}

static void set_width_and_height(sfFloatRect *rect, sfVector2f *size,
sfVector2f *center, int const player)
{
    sfVector2i players = get_display_infos(player);
    sfVector2f ratio = window_get_size_ratio();

    rect->width = 1;
    rect->height = 1;
    if (players.y >= 2)
        rect->width /= 2;
    if (players.y >= 3 && !(players.y % 2 != 0 && players.x % 2 != 0))
        rect->height /= 2;
    size->x = SCREEN_RESOLUTION.x * rect->width;
    size->y = SCREEN_RESOLUTION.y * rect->height;
    rect->width *= ratio.x;
    rect->height *= ratio.y;
    compute_width_and_height(rect, size, center, player);
    if (player < 0) {
        center->x = SCREEN_RESOLUTION.x / 2;
        center->y = SCREEN_RESOLUTION.y / 2;
    }
}

void tick_change_view(int const player)
{
    sfFloatRect view_rect = {0, 0, 1, 1};
    sfView *view = sfView_copy(sfRenderWindow_getView(GAME.window));
    sfVector2f center = sfView_getCenter(view);
    sfVector2f size = sfView_getSize(view);
    sfVector2f ratio = window_get_size_ratio();
    sfVector2i screen = SCREEN_RESOLUTION;

    center.x = (int)(GAME.player[player].position.x * 8);
    center.y = (int)(GAME.player[player].position.y * 8);
    set_width_and_height(&view_rect, &size, &center, player);
    view_rect.width -= ratio.x * ((float)(SPLITSCREEN_WIDTH / 2) / screen.x);
    view_rect.height -= ratio.y * ((float)(SPLITSCREEN_WIDTH / 2) / screen.y);
    sfView_setCenter(view, center);
    sfView_setSize(view, size);
    sfView_setViewport(view, view_rect);
    sfRenderWindow_setView(GAME.window, view);
    if (player < 0)
        set_mouse_position(view);
    sfView_destroy(view);
}

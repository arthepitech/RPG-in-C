/*
** EPITECH PROJECT, 2022
** window/create.c
** File description:
** Create the window
*/

#include "const.h"
#include "files.h"
#include "filepaths.h"
#include "my.h"
#include "struct.h"
#include "texts.h"
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/RenderWindow.h>

static void change_name(sfRenderWindow *window)
{
    int length = 0;
    char **ary = NULL;

    ary = path_form_and_convert(FILE_TITLES_TXT, PATH_MISC);
    if (ary == NULL)
        return;
    for (length = 0; ary[length] != NULL; length++);
    if (length < 1) {
        my_free_char_2d(ary);
        return;
    }
    srand(time(NULL) + (long int)(window));
    if (rand() % 100 < ALTERNATE_NAME_CHANCES * 100) {
        srand(time(NULL) + (long int)(ary) + (long int)rand());
        sfRenderWindow_setTitle(window, ary[rand() % length]);
    }
    my_free_char_2d(ary);
}

static void window_create_icon(void)
{
    unsigned int x = 0;
    unsigned int y = 0;
    sfImage *icon = sfImage_createFromFile("icon.png");

    if (icon == NULL)
        return;
    x = sfImage_getSize(icon).x;
    y = sfImage_getSize(icon).y;
    sfRenderWindow_setIcon(GAME.window, x, y, sfImage_getPixelsPtr(icon));
    sfImage_destroy(icon);
}

void window_create(int const fullscreen)
{
    sfRenderWindow *window = NULL;
    sfVideoMode video_mode = sfVideoMode_getDesktopMode();
    sfUint32 style = WIN_PARAMS;

    if (fullscreen)
        style = WIN_PARAMS_FULLSCREEN;
    window = sfRenderWindow_create(video_mode, GAME_NAME, style, NULL);
    if (window == NULL)
        return;
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_setFramerateLimit(window, DEFAULT_FPS);
    change_name(window);
    GAME.window_fullscreen = fullscreen % 2;
    GAME.window = window;
    if (file_exists("icon.png"))
        window_create_icon();
}

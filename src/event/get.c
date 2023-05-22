/*
** EPITECH PROJECT, 2022
** event/get.c
** File description:
** Searchs an event in files
*/

#include "event.h"
#include "filepaths.h"
#include "files.h"
#include "my.h"
#include "palettes.h"
#include "script.h"
#include <stdlib.h>
#include <SFML/Graphics/Texture.h>

static void extract_display(event_t *event, char const *str)
{
    int length = 0;
    char *path = NULL;
    char **ary = NULL;

    ary = my_str_to_array(str, EVENT_SCRIPT_SEPARATORS);
    if (ary == NULL)
        return;
    for (length = 0; ary[length] != NULL; length++);
    if (length >= 1)
        event->tile->palette = palette_get(ary[0]);
    if (length >= 2)
        event->layer = my_str_to_int(ary[1]);
    if (length >= 3)
        event->view = my_str_to_int(ary[2]);
    my_free_char_2d(ary);
}

static void set_texture(event_t *event, char const *name)
{
    char *path = NULL;

    if (event == NULL || name == NULL)
        return;
    path = path_form(name, PATH_GRAPHICS);
    if (path == NULL)
        return;
    if (file_exists(path))
        event->tile->texture = sfTexture_createFromFile(path, NULL);
    free(path);
}

static void extract_texture(event_t *event, char const *str)
{
    int length = 0;
    char *path = NULL;
    char **ary = NULL;

    ary = my_str_to_array(str, EVENT_SCRIPT_SEPARATORS);
    if (ary == NULL)
        return;
    for (length = 0; ary[length] != NULL; length++);
    if (length >= 1)
        set_texture(event, ary[0]);
    if (length >= 3) {
        event->tile->texture_rect.x = my_str_to_int(ary[1]);
        event->tile->texture_rect.y = my_str_to_int(ary[2]);
    }
    my_free_char_2d(ary);
}

static void event_extract(event_t *event, char * const *ary)
{
    int length = 0;

    for (length = 0; ary[length] != NULL; length++);
    if (length < 1)
        return;
    extract_texture(event, ary[0]);
    if (length < 2)
        return;
    extract_display(event, ary[1]);
    for (int i = 2; ary[i] != NULL; i++)
        event_extract_script(event, ary[i]);
}

event_t *event_get(char const *name)
{
    char **ary = NULL;
    event_t *event = NULL;

    if (name == NULL)
        return NULL;
    event = event_create();
    if (event == NULL)
        return NULL;
    ary = path_form_and_convert(name, PATH_EVENTS);
    if (ary == NULL) {
        event_destroy(event);
        return NULL;
    }
    event_extract(event, ary);
    my_free_char_2d(ary);
    return event;
}

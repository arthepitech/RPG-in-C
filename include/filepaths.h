/*
** EPITECH PROJECT, 2022
** texts.h
** File description:
** Constant values
*/

#pragma once
    #define PATHS_TXT "paths.txt"

enum paths_indices {
    PATH_TEXT,
    PATH_GRAPHICS,
    PATH_SAVED,
    PATH_COLORS,
    PATH_MAPS,
    PATH_PALETTES,
    PATH_TILEMAPS,
    PATH_SCRIPTS,
    PATH_EVENTS,
    PATH_MISC,
    PATH_HITBOXES,
    PATH_ITEMS,
    PATH_MENUS,
    PATH_PARALLAX,
    PATH_MUSICS,
    PATH_ENEMIES,
    PATH_BGM,
    PATH_SFX,
    PATH_TOTAL_SIZE,
};

static const char *PATH_EXTENTIONS[PATH_TOTAL_SIZE] = {
    "", "", "", ".bclr", ".bmap", ".bplt", ".btlm", ".bspt", ".bvnt",
    "", ".bhbx", ".bitm", ".bmns", "bprl", ".bmsc", ".benm", ".ogg", ".ogg"
};

static const char FILE_BATTLE_SELECT[] = "battle/select";
static const char FILE_BATTLE_ZONES[] = "battle/zones";
static const char FILE_CONTROLLER_TXT[] = "controller.txt";
static const char FILE_KEYBOARD_TXT[] = "keyboard.txt";
static const char FILE_INPUTS[] = "inputs";
static const char FILE_MISC_NOTES_PNG[] = "misc/notes.png";
static const char FILE_NOTES_TXT[] = "notes.txt";
static const char FILE_SAVE[] = "save";
static const char FILE_SKIN_TONES_TXT[] = "skin_tones.txt";
static const char FILE_TITLES_TXT[] = "titles.txt";

char **path_form_and_convert(char const *name, int const path_asked);
char *path_form(char const *name, int const path_asked);
char *path_get(int const path_asked);

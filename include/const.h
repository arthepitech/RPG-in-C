/*
** EPITECH PROJECT, 2022
** constants.h
** File description:
** Constant values
*/

#pragma once
    #define PLAYER_MAX 4
    #define SAVED_VARIABLES 50
    #define TILE 8
    #define WIN_PARAMS sfClose | sfResize
    #define WIN_PARAMS_FULLSCREEN sfClose | sfFullscreen

    #include <SFML/System/Vector2.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Window/Window.h>

static const float ALTERNATE_NAME_CHANCES = 0.25;
static const int BATTLE_LOOSE = 1;
static const int BATTLE_WIN = 0;
static const int DEFAULT_FPS = 60;
static const int ENDLESS = 1;
static const int EXIT = 0;
static const int ERROR = 84;
static const int FILE_BUFFER_SIZE = 10000;
static const int MIN_TO_SEC = 60;
static const float NOTE_RANGE = 1.0;
static const float NOTE_SPEED = 9.0;
static const float NOTE_WAIT = 2.0;
static const int SAVED_VARIABLES_BATTLE = 0;
static const int SAVED_VARIABLES_DEFAULT = 0;
static const float PLAYER_SPEED = 6.0;
static const int SEC_TO_MICRO = 1000000;
static const float SPLITSCREEN_WIDTH = 1.0;
static const int WALKING_ANIMATION_FRAMES = 4;
static const int WALKING_ANIMATION_SPEED = 6;
static const sfVector2f POSITION_OUT_OF_SCREEN = {-100, -100};
static const sfVector2i SCREEN_RESOLUTION = {160, 144};
static const sfVector2u WINDOW_SIZE_MAX = {1920, 1080};
static const sfVector2u WINDOW_SIZE_MIN = {800, 600};

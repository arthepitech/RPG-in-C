/*
** EPITECH PROJECT, 2022
** event.h
** File description:
** PNJs and other things
*/

#pragma once
    #define MAX_SCRIPTS_PER_CALLS (int)4
    #define EVENT_VAR_SIZE (int)10
    #define EVENT_VAR_PLAYER (int)0

    #include "tiles.h"
    #include "script.h"
    #include <SFML/System/Vector2.h>

typedef struct script_s script_t;

enum calls_indices {
    CALL_ONLOAD,
    CALL_ONTICK,
    CALL_PLAYERCONTACT,
    CALL_PLAYERINTERACTION,
    CALL_PLAYERTILE,
    CALL_TOTAL_SIZE,
};

static const char *CALL_KEYWORDS[CALL_TOTAL_SIZE] = {
    ">on_load", ">on_tick",
    ">player_contact", ">player_interaction", ">player_tile",
};

typedef struct event_s {
    script_t *script[CALL_TOTAL_SIZE][MAX_SCRIPTS_PER_CALLS];
    sfVector2f position;
    tile_t *tile;
    float variable[EVENT_VAR_SIZE];
    int layer;
    int view;
} event_t;

static const char COMMAND_INSTEAD_OF_SCRIPT[] = "COMMAND";
static const char EVENT_SCRIPT_ENTRIES[] = ">";
static const char EVENT_SCRIPT_SEPARATORS[] = "\t ";

static const sfVector2f EVENT_CONTACT_RANGE = {0.4, 0.4};

//Returns -1 if a problem is encountered
//Otherwise, returns the index of the new script
int event_add_script(event_t *event, char const *name, int const call_idx);
//Returns 1 if a script can be executed
//Otherwise, returns 0
int event_check_player_contact(event_t *event);
//Returns NULL if a problem is encountered
event_t *event_create(void);
//Returns NULL
event_t *event_destroy(event_t *event);
//Returns 0 if a problem is encountered
//Otherwise, returns 1
int event_draw(event_t *event);
//Returns the total of all values returned by script_execute( )
int event_execute(event_t *event, int const call_idx);
void event_extract_script(event_t *event, char const *str);
//Returns NULL if a problem is encountered
event_t *event_get(char const *name);
//Returns 0 if a problem is encountered
float event_variable_get(event_t const *event, int const var_id);

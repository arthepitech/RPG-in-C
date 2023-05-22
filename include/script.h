/*
** EPITECH PROJECT, 2022
** script.h
** File description:
** Multiple commands that can be executed in-game
*/

#pragma once
    #include "event.h"
    #include <stdlib.h>

typedef struct event_s event_t;

typedef struct command_s {
    char **ary;
    int comment;
    int length;
} command_t;

typedef struct script_s {
    command_t *commands;
    int length;
} script_t;

static const char SCRIPT_SYSTEM_INIT[] = "system/initialization";
static const char SCRIPT_SYSTEM_LOAD_MAP[] = "system/load_map";
static const char SCRIPT_SYSTEM_OPEN_MENU[] = "system/open_menu";

static const char CMD_CONDITION_IF[] = "IF";
static const char CMD_CONDITION_UNLESS[] = "UNLESS";

static const char CMD_VAR_CHARACTERS[] = "@";
static const char CMD_VAR_SAVED_CHARACTERS[] = "#";

static const char CMD_SEPARATORS[] = "\t `";
static const char ER_MSG_CANTCMD[] = "Couldn't store a command \"@@\"\n";
static const char ER_MSG_INVCMD[] = "Invalid command format \"@@\"\n";
static const char ER_CMD_INVARG[] = "Unknown value \"@@\"\n";
static const char ER_CMD_INVMAP[] = "Couldn't load \"@@\" as a map\n";
static const char ER_CMD_TOOFEW[] = "Too few arguments for \"@@\"\n";
static const char ER_CMD_TOOMANY[] = "Too many arguments for \"@@\"\n";

//Returns 1 if the function did execute the script
//Otherwise, returns 0
int script_call(char const *name, event_t *event);
command_t command_create(char const *typed);
void command_destroy(command_t command);
//Returns 0
int command_display_error(char const *typed, char const *message);
//Returns 1 if the command executed, and 0 if it didn't
int command_execute(command_t command, event_t *event);
int command_execute_add_equipment(command_t command, event_t *event);
int command_execute_add_music(command_t command, event_t *event);
int command_execute_animate_with_player(command_t command, event_t *event);
int command_execute_call_script(command_t command, event_t *event);
int command_execute_change_fullscreen(command_t command, event_t *event);
int command_execute_change_player_equipment(command_t command, event_t *event);
int command_execute_change_player_skin_tone(command_t command, event_t *event);
int command_execute_dialogue(command_t command, event_t *event);
int command_execute_display(command_t command, event_t *event);
int command_execute_equip_player(command_t command, event_t *event);
int command_execute_exit(command_t command, event_t *event);
int command_execute_go_on_player(command_t command, event_t *event);
int command_execute_move_event(command_t command, event_t *event);
int command_execute_open_menu(command_t command, event_t *event);
int command_execute_place_event(command_t command, event_t *event);
int command_execute_play_bgm(command_t command, event_t *event);
int command_execute_print(command_t command, event_t *event);
int command_execute_reset_palette(command_t command, event_t *event);
int command_execute_save_load(command_t command, event_t *event);
int command_execute_save_new(command_t command, event_t *event);
int command_execute_saved_var_add(command_t command, event_t *event);
int command_execute_saved_var_set(command_t command, event_t *event);
int command_execute_set_alpha(command_t command, event_t *event);
int command_execute_set_palette_player(command_t command, event_t *event);
int command_execute_set_texture_rect(command_t command, event_t *event);
int command_execute_set_view(command_t command, event_t *event);
int command_execute_start_battle(command_t command, event_t *event);
int command_execute_teleport_players(command_t command, event_t *event);
int command_execute_texture_with_player(command_t command, event_t *event);
//
int script_condition_comparison(command_t command, event_t *event);
int script_condition_is_player_connected(command_t command, event_t *event);
//Returns NULL if a problem is encountered
script_t *script_create(void);
//Returns NULL
script_t *script_destroy(script_t *script);
//Returns 0 if the function couldn't find the script, and 1 if it could
int script_execute(script_t *script, event_t *event);
//Returns 0 if a problem is encountered
float command_get_argument(char const *arg, event_t const *event);
//Returns NULL if a problem is encountered
script_t *script_get(char const *name);

//Functions that can be executed by commands
//Has to be in accordance to EXECUTE_KEYS
static int (*EXECUTE_FUNCTIONS[])(command_t, event_t *) = {
    command_execute_add_equipment,
    command_execute_add_music,
    command_execute_animate_with_player,
    command_execute_call_script,
    command_execute_change_fullscreen,
    command_execute_change_player_equipment,
    command_execute_change_player_skin_tone,
    command_execute_dialogue,
    command_execute_display,
    command_execute_equip_player,
    command_execute_exit,
    command_execute_go_on_player,
    command_execute_move_event,
    command_execute_open_menu,
    command_execute_place_event,
    command_execute_play_bgm,
    command_execute_print,
    command_execute_reset_palette,
    command_execute_save_load,
    command_execute_save_new,
    command_execute_saved_var_add,
    command_execute_saved_var_set,
    command_execute_set_alpha,
    command_execute_set_palette_player,
    command_execute_set_texture_rect,
    command_execute_set_view,
    command_execute_start_battle,
    command_execute_teleport_players,
    command_execute_texture_with_player,
    NULL
};
//Key-words that are used by commands to call functions
//Has to be in accordance to EXECUTE_FUNCTIONS
static const char *EXECUTE_KEYS[] = {
    "add_equipment",
    "add_music",
    "animate_with_player",
    "call_script",
    "change_fullscreen",
    "change_player_equipment",
    "change_player_skin_tone",
    "dialogue",
    "display",
    "equip_player",
    "exit",
    "go_on_player",
    "move_event",
    "open_menu",
    "place_event",
    "play_bgm",
    "print",
    "reset_palette",
    "save_load",
    "save_new",
    "saved_var_add",
    "saved_var_set",
    "set_alpha",
    "set_palette_player",
    "set_texture_rect",
    "set_view",
    "start_battle",
    "teleport_players",
    "texture_with_player",
    NULL
};
//Conditions that can be executed by scripts
//Has to be in accordance to CONDITION_KEYS
static int (*CONDITION_FUNCTIONS[])(command_t, event_t *) = {
    script_condition_comparison,
    script_condition_is_player_connected,
    NULL
};
//Key-words that are used by commands to call conditions
//Has to be in accordance to CONDITION_FUNCTIONS
static const char *CONDITION_KEYS[] = {
    "comparison",
    "is_player_connected",
    NULL
};

/*
** EPITECH PROJECT, 2022
** calls.h
** File description:
** Function calls
*/

#pragma once

static const char MAP_EXIT[] = "exit";
static const char SAVE_NOTHING[] = "no_data_here ";

int start(void);
//Returns 0 if there is no save
//Otherwise, returns 1
int save_load(char const *name);
int load_skin_tone(int const id, int const player);
void save_save(char const *name);
void save_write_ary(int const fd, char * const *ary);
void save_write_double(int const fd, float value, int const precision);
void save_write_str(int const fd, char const *str);
void save_write_value(int const fd, int value);
void tick_change_view(int const player);
//Returns 1 if GAME.deltaclock == NULL
//Otherwise, returns 0
int tick_deltaclock(void);
//Returns 0 if no player is connected
//Otherwise, returns 1
int tick_draw_map(void);
//Returns 1 if events were found
//Otherwise, returns 0
int tick_events_update_calls(void);
//Returns 1 if the map is changed
//Otherwise, returns 0
int tick_map_change(void);
void tick_player_input_joysticks(int const player, float *inputs);
void tick_player_inputs(void);
void tick_player_movement(void);
//Returns the amount of events detected
int tick_poll_events(void);
//Returns -1 if the player doesn't exists
//Otherwise, returns deltawalking
int tick_player_walk_animation(int player);

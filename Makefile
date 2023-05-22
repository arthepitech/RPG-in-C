##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile de Bard Tempo Keeper
##

SRC	=	../main.c	\
		battle/enemy/get.c	\
		battle/notes/press/correct.c	\
		battle/notes/press/wrong.c	\
		battle/notes/draw.c	\
		battle/notes/update.c	\
		battle/song/add_note.c	\
		battle/song/get.c	\
		battle/create.c	\
		battle/destroy.c	\
		battle/is_playing.c	\
		battle/select_update.c	\
		battle/select.c	\
		battle/start.c	\
		bgm/free.c	\
		bgm/initialise.c	\
		bgm/play.c	\
		color/get.c	\
		command/execute/add_equipment.c	\
		command/execute/add_music.c	\
		command/execute/animate_with_player.c	\
		command/execute/call_script.c	\
		command/execute/change_fullscreen.c	\
		command/execute/change_player_equipment.c	\
		command/execute/change_player_skin_tone.c	\
		command/execute/dialogue.c	\
		command/execute/display.c	\
		command/execute/equip_player.c	\
		command/execute/exit.c	\
		command/execute/go_on_player.c	\
		command/execute/move_event.c	\
		command/execute/open_menu.c	\
		command/execute/place_event.c	\
		command/execute/play_bgm.c	\
		command/execute/print.c	\
		command/execute/reset_palette.c	\
		command/execute/save_load.c	\
		command/execute/save_new.c	\
		command/execute/saved_var_add.c	\
		command/execute/saved_var_set.c	\
		command/execute/set_alpha.c	\
		command/execute/set_player_palette.c	\
		command/execute/set_texture_rect.c	\
		command/execute/set_view.c	\
		command/execute/start_battle.c	\
		command/execute/teleport_players.c	\
		command/execute/texture_with_player.c	\
		command/create.c	\
		command/destroy.c	\
		command/display_error.c	\
		command/execute.c	\
		command/get_argument.c	\
		event/variable/get.c	\
		event/add_script.c	\
		event/check_player_contact.c	\
		event/create.c	\
		event/destroy.c	\
		event/draw.c	\
		event/execute.c	\
		event/extract_script.c	\
		event/get.c	\
		file/exists.c	\
		file/read.c	\
		file/write.c	\
		game/free.c	\
		game/initialise.c	\
		hitbox/create.c	\
		hitbox/destroy.c	\
		hitbox/get.c	\
		inputs/load.c	\
		inputs/new_controller.c	\
		inputs/save.c	\
		inputs/update.c	\
		item/extract/texture.c	\
		item/add.c	\
		item/create.c	\
		item/destroy.c	\
		item/equip.c	\
		item/get_stats.c	\
		item/get.c	\
		map/check_collisions.c	\
		map/create.c	\
		map/destroy.c	\
		map/draw.c	\
		map/execute.c	\
		map/get.c	\
		map/update_event_layers.c	\
		menu/button/create_default_tile.c	\
		menu/button/create.c	\
		menu/button/destroy.c	\
		menu/button/draw.c	\
		menu/window/create.c	\
		menu/window/destroy.c	\
		menu/window/draw.c	\
		menu/create.c	\
		menu/destroy.c	\
		menu/draw.c	\
		menu/get_button.c	\
		menu/get_event.c	\
		menu/get_window.c	\
		menu/get.c	\
		menu/open.c	\
		menu/update_key.c	\
		menu/update_movement.c	\
		menu/update_name.c	\
		menu/update.c	\
		music/add.c	\
		palette/create.c	\
		palette/destroy.c	\
		palette/get.c	\
		parallax/layer/create.c	\
		parallax/layer/destroy.c	\
		parallax/destroy.c	\
		parallax/initialise.c	\
		path/form_and_convert.c	\
		path/form.c	\
		path/get.c	\
		save/load_skin_tone.c	\
		save/load.c	\
		save/save.c	\
		save/write_ary.c	\
		save/write_str.c	\
		save/write_value.c	\
		script/condition/comparison.c	\
		script/condition/is_player_connected.c	\
		script/call.c	\
		script/create.c	\
		script/destroy.c	\
		script/execute.c	\
		script/get.c	\
		tick/draw/map.c	\
		tick/events/update_calls.c	\
		tick/player/input_joysticks.c	\
		tick/player/inputs.c	\
		tick/player/movement.c	\
		tick/player/walk_animation.c	\
		tick/change_view.c	\
		tick/deltaclock.c	\
		tick/map_change.c	\
		tick/poll_events.c	\
		tile/create.c	\
		tile/destroy.c	\
		tile/draw.c	\
		tilemap/check_collisions.c	\
		tilemap/create.c	\
		tilemap/draw.c	\
		tilemap/destroy.c	\
		tilemap/extract_tile.c	\
		tilemap/get.c	\
		window/create.c	\
		window/destroy.c	\
		window/get_size.c	\
		window/is_open.c	\
		window/resize.c		\
		start.c	\

BUILDDIR = build

OBJ = $(patsubst %.c, $(BUILDDIR)/%.o, $(SRC))

$(BUILDDIR)/%.o: 	src/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

NAME	=	my_rpg

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio \
			-L./lib/my -lmy

IDIR	=	include

CPPFLAGS	=	$(LCSFML) -I$(IDIR) -I./include

CFLAGS	=	-W -Wextra

GCCFLAG	=	gcc -o

FDEBUG	=	-g3

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my/
	$(GCCFLAG) $(NAME) $(OBJ) $(LDFLAGS)

debug:	$(OBJ)
	$(MAKE) -C lib/my/
	$(GCCFLAG) $(NAME) $(OBJ) $(LDFLAGS) $(FDEBUG)

debug_play:	fclean debug
	clear
	valgrind --track-origins=yes ./$(NAME)

clean:
	$(MAKE) clean -C lib/my/
	$(RM) -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C lib/my/
	$(RM) -f $(NAME)

play:	$(NAME)
	./$(NAME)

re:	fclean all

.PHONY: all debug debug_play fclean clean play re

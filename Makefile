CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
PRINTF = ./srcs/printf/libftprintf.a
SRCS =  srcs/libft/ft_strlcat.c srcs/libft/ft_strlcpy.c srcs/libft/ft_strlen.c srcs/libft/ft_strchr.c\
	    srcs/libft/ft_strncmp.c srcs/libft/ft_strdup.c srcs/libft/ft_itoa.c\
	    srcs/map/check_for_collectibles.c srcs/map/check_for_start_exit.c srcs/map/check_for_valid_path.c\
	    srcs/map/check_if_surrounded_by_walls.c srcs/map/map_utils.c srcs/map/map_validator.c\
	    srcs/map/upload_map.c srcs/map/draw_map.c srcs/map/copy_map.c srcs/map/check_is_map_rectangle.c\
	    srcs/ghost/draw_ghsot.c srcs/ghost/ghost_utils.c srcs/ghost/load_ghost_frames.c\
	    srcs/ghost/move_ghost.c srcs/ghost/is_ghost_touches_wall.c srcs/ghost/is_ghost_touches_collectible.c srcs/ghost/get_ghost_position.c\
	    srcs/ghost/is_ghsot_touches_door.c\
	    srcs/door/draw_door.c srcs/door/load_door_frames.c srcs/door/load_wall_surface_collec_frame.c\
	    srcs/hooks/key_press.c srcs/hooks/key_release.c srcs/hooks/set_hooks.c srcs/variables_init.c\
	    srcs/exceptions/map_exceptions.c srcs/exceptions/close_program.c srcs/exceptions/file_exceptions.c\
	    srcs/utils/utils.c srcs/utils/count_collectibles.c srcs/utils/ft_get_name.c srcs/so_long.c\
	    srcs/get_next_line/get_next_line.c srcs/get_next_line/get_next_line_utils.c

SRCSB = srcs/enemy/move_enemy_bonus.c srcs/enemy/enemy_utils_bonus.c srcs/enemy/is_enemy_touches_wall_bonus.c srcs/enemy/animate_enemy_attack_bonus.c\
	    srcs/enemy/draw_enemy_bonus.c srcs/enemy/animate_and_move_enemy_bonus.c srcs/enemy/load_enemy_frames_bonus.c srcs/enemy/set_enemies_pos_bonus.c\
		srcs/ghost/is_ghost_touches_enemy_bonus.c srcs/ghost/animate_death_bonus.c srcs/ghost/animate_disappear_bonus.c srcs/ghost/animate_and_move_ghost_bonus.c\
		srcs/door/animate_door_bonus.c 

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(PRINTF) $(OBJS) $(OBJSB)
	$(CC) $(CFLAGS) $(OBJS) $(OBJSB) $(PRINTF) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(NAME)

$(PRINTF):
	@make -C ./srcs/printf

clean:
	rm -f $(OBJS) $(OBJSB)
	@cd srcs/printf && $(MAKE) clean
	
fclean: clean
	rm -f $(NAME)
	@cd srcs/printf && $(MAKE) fclean
	
re: fclean all
.PHONY: all clean fclean re

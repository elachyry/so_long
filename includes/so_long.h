/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   so_long.h										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: melachyr <melachyr@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/05 13:04:18 by melachyr		  #+#	#+#			 */
/*   Updated: 2024/01/09 13:54:43 by melachyr		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "stdbool.h"
# include <mlx.h>
# include <math.h>
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct t_game
{
	void	*mlx;
	void	*win;
	int		walk_frame[11];
	void	*right_walk_frames[8];
	void	*left_walk_frames[8];
	void	*right_jump_frames[8];
	void	*left_jump_frames[8];
	void	*right_attack_frames[8];
	void	*left_attack_frames[8];
	void	*right_death_frames[8];
	void	*left_death_frames[8];
	void	*right_disappear_frames[8];
	void	*left_disappear_frames[8];
	void	*right_enemie_frames[8];
	void	*left_enemie_frames[8];
	void	*left_enemie_attack_frames[8];
	void	*right_enemie_attack_frames[8];
	double	ghost_x_y[2];
	double	enemie_x_y[10][2];
	void	*door_frames[6];
	int		door_x_y[2];
	int		**map;
	int		map_dimension[2];
	int		current_direction;
	int		current_enemy_direction[10];
	int		collectible_count;
	int		is_long_press;
	int		wall_size;
	int		number_moves;
	int		current_move;
	int		enemies_number;
	bool	is_door_open[2];
	void	*obstacle_image;
	void	*surface_image;
	void	*collectible_image;
}	t_ghost;

//libft
char	*ft_itoa_2(int n);
char	*ft_strdup_2(const char *s1);
char	*ft_strlcat(char *dest, const char *src);
char	*ft_strchr(const char *str, int c);
char	*ft_strlcpy(char *dst, const char *src);
int		ft_strlen_2(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);

//map
bool	check_for_collectibles(int **map, int width, int height);
bool	check_for_start_exit(int **map, int width, int height);
bool	check_for_valid_path(t_ghost *ghost);
bool	check_if_surrounded_by_walls(int **map, int width, int height);
bool	check_is_map_rectangle(int height, char *path);
void	check_map_extention(char *filename);
void	check_map(t_ghost *ghost);
void	free_map(int **map, int lengh);
void	draw_map(t_ghost *ghost);
void	upload_map(t_ghost *ghost, char *path);
int		get_map_height(char *path);
int		**copy_map(t_ghost *ghost);

//ghost
void	draw_ghost(t_ghost *ghost, int move);
void	load_ghost_frames(t_ghost *ghost);
void	get_ghost_position(t_ghost *ghost);
void	move_ghost(t_ghost *ghost, int direction, int distance);
void	animate_and_move_ghost(t_ghost *ghost);
void	animate_death(t_ghost *ghost);
void	animate_disappear(t_ghost *ghost);
void	ghost_exit(t_ghost *ghost);
void	is_ghost_touches_collectible(t_ghost *ghost, int direction);
bool	is_ghost_touches_wall(t_ghost *ghost, int direction);
bool	is_ghsot_touches_door(t_ghost *ghost, int direction);
bool	is_ghost_touches_enemy(t_ghost *ghost, int direction, int e);

//enemy
void	load_enemy_frames(t_ghost *ghost);
void	game_over(t_ghost *ghost, int e);
void	draw_enemy(t_ghost *ghost, int move, int e);
void	move_enemy(t_ghost *ghost, int direction, double distance, int e);
bool	is_enemy_touches_wall(t_ghost *ghost, int direction, int e);
void	animate_enemy_attack(int direction, t_ghost *ghost, int e);
void	animate_and_move_enemy(t_ghost *ghost);
void	enemy_change_direction(t_ghost *ghost, int e);
void	set_enemies_pos(t_ghost *ghost);
int		animate_enemy_loop(t_ghost *ghost);

//door
void	animate_door(t_ghost *ghost);
void	draw_door(t_ghost *ghost, int move);
void	load_door_frames(t_ghost *ghost);
void	load_wall_surface_collec_frame(t_ghost *ghost);

//hooks
int		key_press(int keycode, t_ghost *ghost);
int		key_release(int keycode, t_ghost *ghost);
void	set_hooks(t_ghost *ghost);

//exceptions
void	components_exception(t_ghost *ghost);
void	path_exception(t_ghost *ghost);
void	collectibles_exception(t_ghost *ghost);
void	start_exit_exception(t_ghost *ghost);
void	surrounded_by_walls_exception(t_ghost *ghost, int type);
void	file_not_found(t_ghost *ghost, char *filename);
void	map_file_empty(void);
void	map_extention_wrong(void);
void	map_file_not_exist(void);
void	close_program(void);

//utils
int		close_window(t_ghost *ghost);
void	count_collectibles(t_ghost *ghost);
void	custom_delay(int microseconds);
char	*ft_get_name(char *result, char *path, int number);

//variables_init
void	variable_init(t_ghost *ghost);
bool	init_tests(t_ghost *ghost, char *path);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:06:45 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/20 10:15:46 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	init_tests(t_ghost *app, char *path)
{
	int	fd;

	app->map_dimension[1] = get_map_height(path);
	fd = open(path, O_RDWR);
	if (fd == -1)
		map_file_not_exist();
	check_map_extention(path);
	app->map = (int **)malloc(sizeof(int *) * app->map_dimension[1]);
	if (app->map == NULL)
		close_program();
	app->wall_size = 48;
	upload_map(app, path);
	if (!check_is_map_rectangle(app->map_dimension[1], path))
		surrounded_by_walls_exception(app, 1);
	app->map_dimension[1] = get_map_height(path);
	check_map(app);
	return (true);
}

static void	enemy_direction_init(t_ghost *app)
{
	app->current_enemy_direction[0] = 5;
	app->current_enemy_direction[1] = 5;
	app->current_enemy_direction[2] = 5;
	app->current_enemy_direction[3] = 5;
	app->current_enemy_direction[4] = 5;
	app->current_enemy_direction[5] = 5;
	app->current_enemy_direction[6] = 5;
	app->current_enemy_direction[7] = 5;
	app->current_enemy_direction[8] = 5;
	app->current_enemy_direction[9] = 5;
}

static void	walk_frame_init(t_ghost *app)
{
	app->walk_frame[0] = 0;
	app->walk_frame[1] = 0;
	app->walk_frame[2] = 0;
	app->walk_frame[3] = 0;
	app->walk_frame[4] = 0;
	app->walk_frame[5] = 0;
	app->walk_frame[6] = 0;
	app->walk_frame[7] = 0;
	app->walk_frame[8] = 0;
	app->walk_frame[9] = 0;
	app->walk_frame[10] = 0;
}

void	variable_init(t_ghost *app)
{
	app->current_direction = 0;
	app->is_long_press = 0;
	app->is_door_open[0] = false;
	app->is_door_open[1] = false;
	app->number_moves = 0;
	app->enemies_number = 8;
	app->obstacle_image = NULL;
	enemy_direction_init(app);
	walk_frame_init(app);
	set_enemies_pos(app);
	load_ghost_frames(app);
	load_enemy_frames(app);
	load_wall_surface_collec_frame(app);
	load_door_frames(app);
}

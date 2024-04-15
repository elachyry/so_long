/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_valid_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:41:11 by melachyr          #+#    #+#             */
/*   Updated: 2024/02/01 15:23:48 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	flood_map(t_ghost *app, int **map_tmp, int x, int y)
{
	if (x < 0 || y < 0 || x >= app->map_dimension[0]
		|| y >= app->map_dimension[1])
		return ;
	if ((map_tmp[y][x] == 0 || map_tmp[y][x] == 3
		|| map_tmp[y][x] == -1 || map_tmp[y][x] == 2))
	{
		map_tmp[y][x] = -2;
		flood_map(app, map_tmp, x + 1, y);
		flood_map(app, map_tmp, x - 1, y);
		flood_map(app, map_tmp, x, y + 1);
		flood_map(app, map_tmp, x, y - 1);
	}
}

bool	check_for_valid_path(t_ghost *app)
{
	int		i;
	int		j;
	int		**map_tmp;
	bool	result;

	map_tmp = copy_map(app);
	if (map_tmp == NULL)
		close_program();
	get_ghost_position(app);
	flood_map(app, map_tmp, app->ghost_x_y[0] / app->wall_size,
		app->ghost_x_y[1] / app->wall_size);
	i = 0;
	result = true;
	while (i < app->map_dimension[1])
	{
		j = -1;
		while (++j < app->map_dimension[0])
		{
			if (map_tmp[i][j] == 3 || map_tmp[i][j] == -1)
				result = false;
		}
		i++;
	}
	free_map(map_tmp, app->map_dimension[1]);
	return (result);
}

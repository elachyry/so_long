/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ghost_touches_collectible.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:04:21 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	check_right(t_ghost *app, int direction, int ghost_directions[4])
{
	int	wall_directions[4];

	if (direction == 0)
	{
		wall_directions[1] = ghost_directions[1] / app->wall_size;
		wall_directions[2] = (ghost_directions[2] + 1) / app->wall_size;
		wall_directions[3] = (ghost_directions[3] - 1) / app->wall_size;
		if (app->map[wall_directions[2]][wall_directions[1]] == 3)
		{
			app->map[wall_directions[2]][wall_directions[1]] = 0;
			app->collectible_count--;
		}
		else if (app->map[wall_directions[3]][wall_directions[1]] == 3)
		{
			app->map[wall_directions[3]][wall_directions[1]] = 0;
			app->collectible_count--;
		}
	}
}

static void	check_left(t_ghost *app, int direction, int ghost_directions[4])
{
	int	wall_directions[4];

	if (direction == 1)
	{
		wall_directions[0] = ghost_directions[0] / app->wall_size;
		wall_directions[2] = (ghost_directions[2] + 1) / app->wall_size;
		wall_directions[3] = (ghost_directions[3] - 1) / app->wall_size;
		if (app->map[wall_directions[2]][wall_directions[0]] == 3)
		{
			app->map[wall_directions[2]][wall_directions[0]] = 0;
			app->collectible_count--;
		}
		else if (app->map[wall_directions[3]][wall_directions[0]] == 3)
		{
			app->map[wall_directions[3]][wall_directions[0]] = 0;
			app->collectible_count--;
		}
	}
}

static void	check_top(t_ghost *app, int direction, int ghost_directions[4])
{
	int	wall_directions[4];

	if (direction == 2)
	{
		wall_directions[0] = (ghost_directions[0] + 1) / app->wall_size;
		wall_directions[1] = (ghost_directions[1] - 1) / app->wall_size;
		wall_directions[2] = ghost_directions[2] / app->wall_size;
		if (app->map[wall_directions[2]][wall_directions[0]] == 3)
		{
			app->map[wall_directions[2]][wall_directions[0]] = 0;
			app->collectible_count--;
		}
		else if (app->map[wall_directions[2]][wall_directions[1]] == 3)
		{
			app->map[wall_directions[2]][wall_directions[1]] = 0;
			app->collectible_count--;
		}
	}
}

static void	check_bottom(t_ghost *app, int direction, int ghost_directions[4])
{
	int	wall_directions[4];

	if (direction == 3)
	{
		wall_directions[0] = (ghost_directions[0] + 1) / app->wall_size;
		wall_directions[1] = (ghost_directions[1] - 1) / app->wall_size;
		wall_directions[3] = ghost_directions[3] / app->wall_size;
		if (app->map[wall_directions[3]][wall_directions[0]] == 3)
		{
			app->map[wall_directions[3]][wall_directions[0]] = 0;
			app->collectible_count--;
		}
		else if (app->map[wall_directions[3]][wall_directions[1]] == 3)
		{
			app->map[wall_directions[3]][wall_directions[1]] = 0;
			app->collectible_count--;
		}
	}
}

void	is_ghost_touches_collectible(t_ghost *app, int direction)
{
	int	ghost_directions[4];

	ghost_directions[0] = app->ghost_x_y[0] + 15;
	ghost_directions[1] = app->ghost_x_y[0] + 15;
	ghost_directions[2] = app->ghost_x_y[1] + 20;
	ghost_directions[3] = app->ghost_x_y[1] + 20;
	check_right(app, direction, ghost_directions);
	check_left(app, direction, ghost_directions);
	check_top(app, direction, ghost_directions);
	check_bottom(app, direction, ghost_directions);
	if (app->collectible_count == 0 && !app->is_door_open[1])
	{
		app->is_door_open[0] = true;
		app->is_door_open[1] = true;
	}
}

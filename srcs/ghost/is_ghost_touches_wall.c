/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ghost_touches_wall.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:33:21 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static bool	check_right(t_ghost *app, int direction, int ghost_directions[4])
{
	int	wall_directions[4];

	if (direction == 0)
	{
		wall_directions[1] = ghost_directions[1] / app->wall_size;
		wall_directions[2] = (ghost_directions[2] + 1) / app->wall_size;
		wall_directions[3] = (ghost_directions[3] - 1) / app->wall_size;
		if (app->map[wall_directions[2]][wall_directions[1]] == 1
			|| app->map[wall_directions[3]][wall_directions[1]] == 1)
			return (true);
	}
	return (false);
}

static bool	check_left(t_ghost *app, int direction, int ghost_directions[4])
{
	int	wall_directions[4];

	if (direction == 1)
	{
		wall_directions[0] = ghost_directions[0] / app->wall_size;
		wall_directions[2] = (ghost_directions[2] + 1) / app->wall_size;
		wall_directions[3] = (ghost_directions[3] - 1) / app->wall_size;
		if (app->map[wall_directions[2]][wall_directions[0]] == 1
			|| app->map[wall_directions[3]][wall_directions[0]] == 1)
			return (true);
	}
	return (false);
}

static bool	check_top(t_ghost *app, int direction, int ghost_directions[4])
{
	int	wall_directions[4];

	if (direction == 2)
	{
		wall_directions[0] = (ghost_directions[0] + 1) / app->wall_size;
		wall_directions[1] = (ghost_directions[1] - 1) / app->wall_size;
		wall_directions[2] = ghost_directions[2] / app->wall_size;
		if (app->map[wall_directions[2]][wall_directions[0]] == 1
			|| app->map[wall_directions[2]][wall_directions[1]] == 1)
			return (true);
	}
	return (false);
}

static bool	check_bottom(t_ghost *app, int direction, int ghost_directions[4])
{
	int	wall_directions[4];

	if (direction == 3)
	{
		wall_directions[0] = (ghost_directions[0] + 1) / app->wall_size;
		wall_directions[1] = (ghost_directions[1] - 1) / app->wall_size;
		wall_directions[3] = ghost_directions[3] / app->wall_size;
		if (app->map[wall_directions[3]][wall_directions[0]] == 1
			|| app->map[wall_directions[3]][wall_directions[1]] == 1)
			return (true);
	}
	return (false);
}

bool	is_ghost_touches_wall(t_ghost *app, int direction)
{
	int	ghost_directions[4];

	ghost_directions[0] = app->ghost_x_y[0] - 3;
	ghost_directions[1] = app->ghost_x_y[0] + 19;
	ghost_directions[2] = app->ghost_x_y[1] - 3;
	ghost_directions[3] = app->ghost_x_y[1] + 29;
	if (check_right(app, direction, ghost_directions))
		return (true);
	if (check_left(app, direction, ghost_directions))
		return (true);
	if (check_top(app, direction, ghost_directions))
		return (true);
	if (check_bottom(app, direction, ghost_directions))
		return (true);
	return (false);
}

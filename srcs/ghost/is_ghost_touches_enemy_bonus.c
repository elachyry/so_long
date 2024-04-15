/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ghost_touches_enemy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:42:10 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static bool	check_right(int direction, int ghost_directions[4],
	int enemy_directions[4])
{
	if (direction == 6)
	{
		if (ghost_directions[1] > enemy_directions[0]
			&& ghost_directions[0] < enemy_directions[1]
			&& ghost_directions[3] > enemy_directions[2]
			&& ghost_directions[2] < enemy_directions[3])
			return (true);
	}
	return (false);
}

static bool	check_left(int direction, int ghost_directions[4],
	int enemy_directions[4])
{
	if (direction == 5)
	{
		if (ghost_directions[1] > enemy_directions[0]
			&& ghost_directions[0] < enemy_directions[1]
			&&ghost_directions[3] > enemy_directions[2]
			&& ghost_directions[2] < enemy_directions[3])
			return (true);
	}
	return (false);
}

bool	is_ghost_touches_enemy(t_ghost *app, int direction, int e)
{
	int	enemy_directions[4];
	int	ghost_directions[4];

	enemy_directions[0] = app->enemie_x_y[e][0] - 15;
	enemy_directions[1] = app->enemie_x_y[e][0] + 15;
	enemy_directions[2] = app->enemie_x_y[e][1] - 5;
	enemy_directions[3] = app->enemie_x_y[e][1] + 5;
	ghost_directions[0] = app->ghost_x_y[0];
	ghost_directions[1] = app->ghost_x_y[0];
	ghost_directions[2] = app->ghost_x_y[1];
	ghost_directions[3] = app->ghost_x_y[1] + 15;
	if (check_right(direction, ghost_directions, enemy_directions))
		return (true);
	if (check_left(direction, ghost_directions, enemy_directions))
		return (true);
	return (false);
}

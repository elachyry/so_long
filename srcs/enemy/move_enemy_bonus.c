/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:33:21 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_enemy(t_ghost *app, int direction, double distance, int e)
{
	if (is_ghost_touches_enemy(app, app->current_enemy_direction[e], e))
		game_over(app, e);
	if (is_enemy_touches_wall(app, direction, e))
	{
		enemy_change_direction(app, e);
		return ;
	}
	if (direction == 5)
		app->enemie_x_y[e][0] += distance;
	else if (direction == 6)
		app->enemie_x_y[e][0] -= distance;
}

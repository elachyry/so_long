/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ghost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:31:37 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_ghost(t_ghost *app, int direction, int distance)
{
	int	i;

	i = 0;
	while (i < distance)
	{
		if (!is_ghost_touches_wall(app, direction))
		{
			if (direction == 0)
				app->ghost_x_y[0]++;
			else if (direction == 1)
				app->ghost_x_y[0]--;
			else if (direction == 2)
				app->ghost_x_y[1]--;
			else if (direction == 3)
				app->ghost_x_y[1]++;
		}
		is_ghost_touches_collectible(app, direction);
		if (is_ghsot_touches_door(app, direction))
			ghost_exit(app);
		i++;
	}
}

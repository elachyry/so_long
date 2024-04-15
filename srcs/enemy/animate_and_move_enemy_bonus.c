/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_and_move_enemy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:01:31 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	animate_enemy_loop(t_ghost *app)
{
	animate_and_move_enemy(app);
	draw_map(app);
	return (1);
}

void	animate_and_move_enemy(t_ghost *app)
{
	int	i;
	int	e;

	i = 0;
	while (i < 6)
	{
		e = 0;
		while (e < app->enemies_number)
		{
			app->walk_frame[app->current_enemy_direction[e]] = i;
			if (is_enemy_touches_wall(app, app->current_enemy_direction[e], e))
			{
				enemy_change_direction(app, e);
				break ;
			}
			draw_enemy(app, app->current_enemy_direction[e], e);
			move_enemy(app, app->current_enemy_direction[e], 0.5, e);
			if (is_ghost_touches_enemy(app, app->current_enemy_direction[e], e))
				game_over(app, e);
			e++;
		}
		mlx_do_sync(app->mlx);
		i++;
	}
}

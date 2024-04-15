/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_and_move_ghost.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:43:26 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	print_number_of_moves(t_ghost *app)
{
	if (!is_ghost_touches_wall(app, app->current_move))
	{
		app->number_moves++;
		ft_printf("number of moves = %d\n", app->number_moves);
	}
}

static void	animate_move_enemy(t_ghost *app, int i, int e)
{
	while (e < app->enemies_number)
	{
		if (i > 5)
			app->walk_frame[app->current_enemy_direction[e]] = i - 5;
		else
			app->walk_frame[app->current_enemy_direction[e]] = i;
		app->walk_frame[app->current_move] = i;
		draw_enemy(app, app->current_enemy_direction[e], e);
		move_enemy(app, app->current_enemy_direction[e], 1, e);
		e++;
	}
}

void	animate_and_move_ghost(t_ghost *app)
{
	int	i;
	int	e;

	i = 0;
	while (i < 8 && app->is_long_press)
	{
		e = 0;
		mlx_clear_window(app->mlx, app->win);
		draw_map(app);
		animate_move_enemy(app, i, e);
		if (is_ghost_touches_wall(app, app->current_move))
			break ;
		draw_ghost(app, app->current_move);
		mlx_do_sync(app->mlx);
		move_ghost(app, app->current_move, 2);
		if (app->is_door_open[0])
		{
			app->is_door_open[0] = false;
			animate_door(app);
		}
		i++;
	}
	print_number_of_moves(app);
}

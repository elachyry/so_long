/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ghsot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:51:22 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	draw_ghsot_right_left(t_ghost *app, int move)
{
	if (move == 0)
		mlx_put_image_to_window(app->mlx, app->win,
			app->right_walk_frames[app->walk_frame[move]],
			app->ghost_x_y[0], app->ghost_x_y[1]);
	if (move == 1)
		mlx_put_image_to_window(app->mlx, app->win,
			app->left_walk_frames[app->walk_frame[move]],
			app->ghost_x_y[0], app->ghost_x_y[1]);
}

static void	draw_ghsot_top_bottom(t_ghost *app, int move)
{
	if (app->current_direction == 0)
		mlx_put_image_to_window(app->mlx, app->win,
			app->right_jump_frames[app->walk_frame[move]],
			app->ghost_x_y[0], app->ghost_x_y[1]);
	else if (app->current_direction == 1)
		mlx_put_image_to_window(app->mlx, app->win,
			app->left_jump_frames[app->walk_frame[move]],
			app->ghost_x_y[0], app->ghost_x_y[1]);
}

static void	draw_ghsot_death(t_ghost *app, int move)
{
	if (app->current_direction == 0)
		mlx_put_image_to_window(app->mlx, app->win,
			app->right_death_frames[app->walk_frame[move]],
			app->ghost_x_y[0], app->ghost_x_y[1]);
	else if (app->current_direction == 1)
		mlx_put_image_to_window(app->mlx, app->win,
			app->left_death_frames[app->walk_frame[move]],
			app->ghost_x_y[0], app->ghost_x_y[1]);
}

static void	draw_ghsot_disappear(t_ghost *app, int move)
{
	if (app->current_direction == 0)
		mlx_put_image_to_window(app->mlx, app->win,
			app->right_disappear_frames[app->walk_frame[move]],
			app->ghost_x_y[0], app->ghost_x_y[1]);
	else if (app->current_direction == 1)
		mlx_put_image_to_window(app->mlx, app->win,
			app->left_disappear_frames[app->walk_frame[move]],
			app->ghost_x_y[0], app->ghost_x_y[1]);
}

void	draw_ghost(t_ghost *app, int move)
{
	if (move == 0 || move == 1)
		draw_ghsot_right_left(app, move);
	else if (move == 2 || move == 3)
		draw_ghsot_top_bottom(app, move);
	else if (move == 8)
		draw_ghsot_death(app, move);
	else if (move == 10)
		draw_ghsot_disappear(app, move);
}

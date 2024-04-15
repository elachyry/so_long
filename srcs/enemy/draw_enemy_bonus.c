/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:06:54 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:04:55 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_enemy(t_ghost *app, int move, int e)
{
	if (app->enemie_x_y[e][0] == 0 && app->enemie_x_y[e][1] == 0)
		return ;
	if (move == 5)
		mlx_put_image_to_window(app->mlx, app->win,
			app->right_enemie_frames[app->walk_frame[move]],
			app->enemie_x_y[e][0], app->enemie_x_y[e][1]);
	else if (move == 6)
		mlx_put_image_to_window(app->mlx, app->win,
			app->left_enemie_frames[app->walk_frame[move]],
			app->enemie_x_y[e][0], app->enemie_x_y[e][1]);
	else if (move == 7)
	{
		if (app->current_enemy_direction[e] == 5)
			mlx_put_image_to_window(app->mlx, app->win,
				app->right_enemie_attack_frames[app->walk_frame[move]],
				app->enemie_x_y[e][0], app->enemie_x_y[e][1]);
		else if (app->current_enemy_direction[e] == 6)
			mlx_put_image_to_window(app->mlx, app->win,
				app->left_enemie_attack_frames[app->walk_frame[move]],
				app->enemie_x_y[e][0], app->enemie_x_y[e][1]);
	}
}

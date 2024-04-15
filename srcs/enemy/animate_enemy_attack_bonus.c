/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_enemy_attack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:58:04 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	animate_enemy_attack(int direction, t_ghost *app, int e)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		app->walk_frame[direction] = i;
		mlx_clear_window(app->mlx, app->win);
		draw_map(app);
		draw_enemy(app, direction, e);
		mlx_do_sync(app->mlx);
		i++;
	}
}

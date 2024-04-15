/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_disappear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:45:31 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	animate_disappear(t_ghost *app)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		app->walk_frame[10] = i;
		app->current_move = 10;
		mlx_clear_window(app->mlx, app->win);
		draw_map(app);
		draw_ghost(app, 10);
		mlx_do_sync(app->mlx);
		custom_delay(900000);
		i++;
	}
}

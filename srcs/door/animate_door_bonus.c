/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_door.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:34:42 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	animate_door(t_ghost *app)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		app->walk_frame[9] = i;
		mlx_clear_window(app->mlx, app->win);
		draw_map(app);
		draw_door(app, 9);
		mlx_do_sync(app->mlx);
		i++;
	}
}

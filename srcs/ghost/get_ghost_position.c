/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ghost_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:50:33 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_ghost_position(t_ghost *app)
{
	int	i;
	int	j;

	i = 0;
	while (i < app->map_dimension[1])
	{
		j = 0;
		while (j < app->map_dimension[0])
		{
			if (app->map[i][j] == 2)
			{
				app->ghost_x_y[0] = j * app->wall_size + 15 ;
				app->ghost_x_y[1] = i * app->wall_size + 15 ;
			}
			j++;
		}
		i++;
	}
}

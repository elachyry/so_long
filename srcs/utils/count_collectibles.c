/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_collectibles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:34:51 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 10:58:33 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	count_collectibles(t_ghost*ghost)
{
	int	i;
	int	j;

	i = 0;
	ghost->collectible_count = 0;
	while (i < ghost->map_dimension[1])
	{
		j = 0;
		while (j < ghost->map_dimension[0])
		{
			if (ghost->map[i][j] == 3)
				ghost->collectible_count++;
			if (ghost->map[i][j] == -1)
			{
				ghost->door_x_y[0] = j * ghost->wall_size;
				ghost->door_x_y[1] = i * ghost->wall_size;
			}
			j++;
		}
		i++;
	}
}

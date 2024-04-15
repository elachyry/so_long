/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_surrounded_by_walls.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:47:56 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/16 16:36:40 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool	check_if_surrounded_by_walls(int **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (i == 0 || j == 0 || j == width - 1 || i == height - 1)
			{
				if (map[i][j] == 0)
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

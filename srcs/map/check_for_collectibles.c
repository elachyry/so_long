/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_collectibles.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:45:24 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/16 16:36:28 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool	check_for_collectibles(int **map, int width, int height)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 3)
				c++;
			j++;
		}
		i++;
	}
	if (c < 1)
		return (false);
	return (true);
}

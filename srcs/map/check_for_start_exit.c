/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_start_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:46:20 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/16 16:36:31 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool	check_for_start_exit(int **map, int width, int height)
{
	int	i;
	int	j;
	int	e;
	int	s;

	i = 0;
	e = 0;
	s = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 2)
				s++;
			if (map[i][j] == -1)
				e++;
			j++;
		}
		i++;
	}
	if (e == 0 || s == 0 || e > 1 || s > 1)
		return (false);
	return (true);
}

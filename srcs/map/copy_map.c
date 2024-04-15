/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:40:45 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	**copy_map(t_ghost *app)
{
	int	**tmp_map;
	int	i;
	int	j;

	tmp_map = (int **)malloc(sizeof(int *) * app->map_dimension[1]);
	if (tmp_map == NULL)
		return (NULL);
	i = 0;
	while (i < app->map_dimension[1])
	{
		tmp_map[i] = malloc(sizeof(int) * app->map_dimension[0]);
		if (tmp_map[i] == NULL)
		{
			free_map(tmp_map, i);
			return (NULL);
		}
		j = 0;
		while (j < app->map_dimension[0])
		{
			tmp_map[i][j] = app->map[i][j];
			j++;
		}
		i++;
	}
	return (tmp_map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:30:28 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/20 11:09:18 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	close_window(t_ghost*ghost)
{
	mlx_destroy_window(ghost->mlx, ghost->win);
	exit(0);
}

void	custom_delay(int microseconds)
{
	double	dummy;
	int		i;

	i = 0;
	dummy = 0.0;
	while (i < microseconds)
	{
		dummy += sin(i) * cos(i);
		i++;
	}
}

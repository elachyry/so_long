/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_exceptions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:51:09 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/20 11:09:05 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	components_exception(t_ghost *app)
{
	free_map(app->map, app->map_dimension[1]);
	ft_printf("The map can be composed only of 0 1 C E P!\n");
	exit(1);
}

void	surrounded_by_walls_exception(t_ghost *app, int type)
{
	free_map(app->map, app->map_dimension[1]);
	if (type == 0)
		ft_printf("The map must be surrounded by walls!\n");
	else if (type == 1)
		ft_printf("The map must be rectangular!\n");
	exit(1);
}

void	start_exit_exception(t_ghost *app)
{
	free_map(app->map, app->map_dimension[1]);
	ft_printf("The map must contain 1 exit, and 1 starting position!\n");
	exit(1);
}

void	collectibles_exception(t_ghost *app)
{
	free_map(app->map, app->map_dimension[1]);
	ft_printf("The map must contain at least 1 collectible!\n");
	exit(1);
}

void	path_exception(t_ghost *app)
{
	free_map(app->map, app->map_dimension[1]);
	ft_printf("there’s not a valid path in the map!\n");
	exit(1);
}

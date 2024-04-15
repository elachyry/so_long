/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:03:36 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_map(t_ghost *app)
{
	int	width;
	int	height;

	width = app->map_dimension[0];
	height = app->map_dimension[1];
	if (!check_if_surrounded_by_walls(app->map, width, height))
		surrounded_by_walls_exception(app, 0);
	if (!check_for_start_exit(app->map, width, height))
		start_exit_exception(app);
	if (!check_for_collectibles(app->map, width, height))
		collectibles_exception(app);
	if (!check_for_valid_path(app))
		path_exception(app);
}

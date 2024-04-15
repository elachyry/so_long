/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_wall_surface_collec_frame.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:44:46 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	load_wall_surface_collec_frame(t_ghost *app)
{
	int	width;
	int	height;

	if (open("images/xpm/others/wall.xpm", O_RDWR) == -1)
		file_not_found(app, "images/xpm/others/wall.xpm");
	app->obstacle_image
		= mlx_xpm_file_to_image(app->mlx,
			"images/xpm/others/wall.xpm", &width, &height);
	if (open("images/xpm/others/surface.xpm", O_RDWR) == -1)
		file_not_found(app, "images/xpm/others/surface.xpm");
	app->surface_image
		= mlx_xpm_file_to_image(app->mlx,
			"images/xpm/others/surface.xpm", &width, &height);
	if (open("images/xpm/others/collectible.xpm", O_RDWR) == -1)
		file_not_found(app, "images/xpm/others/collectible.xpm");
	app->collectible_image
		= mlx_xpm_file_to_image(app->mlx,
			"images/xpm/others/collectible.xpm", &width, &height);
}

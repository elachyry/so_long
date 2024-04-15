/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_door_frames.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:40:17 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	load_door_frames(t_ghost *app)
{
	int		width;
	int		height;
	int		i;
	char	*filename;

	i = 0;
	while (i < 6)
	{
		filename = malloc(sizeof(char) * 100);
		if (filename == NULL)
			return ;
		ft_get_name(filename, "images/xpm/door/door_", i);
		if (open(filename, O_RDWR) == -1)
			file_not_found(app, filename);
		app->door_frames[i++]
			= mlx_xpm_file_to_image(app->mlx, filename, &width, &height);
		free(filename);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_enemy_frames.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:19:46 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	load_walk_frames(t_ghost *app)
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
		ft_get_name(filename, "images/xpm/enemy/walk/right/enemy_", i);
		if (open(filename, O_RDWR) == -1)
			file_not_found(app, filename);
		app->right_enemie_frames[i]
			= mlx_xpm_file_to_image(app->mlx, filename, &width, &height);
		ft_get_name(filename, "images/xpm/enemy/walk/left/enemy_left_", i);
		if (open(filename, O_RDWR) == -1)
			file_not_found(app, filename);
		app->left_enemie_frames[i++]
			= mlx_xpm_file_to_image(app->mlx, filename, &width, &height);
		free(filename);
	}
}

static void	load_attack_frames(t_ghost *app)
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
		ft_get_name(filename,
			"images/xpm/enemy/attack/right/enemy_attack_", i);
		if (open(filename, O_RDWR) == -1)
			file_not_found(app, filename);
		app->right_enemie_attack_frames[i]
			= mlx_xpm_file_to_image(app->mlx, filename, &width, &height);
		ft_get_name(filename,
			"images/xpm/enemy/attack/left/enemy_attack_left_", i);
		if (open(filename, O_RDWR) == -1)
			file_not_found(app, filename);
		app->left_enemie_attack_frames[i++]
			= mlx_xpm_file_to_image(app->mlx, filename, &width, &height);
		free(filename);
	}
}

void	load_enemy_frames(t_ghost *app)
{
	load_walk_frames(app);
	load_attack_frames(app);
}

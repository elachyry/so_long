/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_ghost_frames.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:15:22 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 12:31:38 by melachyr         ###   ########.fr       */
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
	while (i < 8)
	{
		filename = malloc(sizeof(char) * 100);
		if (filename == NULL)
			return ;
		ft_get_name(filename, "images/xpm/ghost/walk/right/ghost_walk_", i);
		if (open(filename, O_RDWR) == -1)
			file_not_found(app, filename);
		app->right_walk_frames[i]
			= mlx_xpm_file_to_image(app->mlx, filename, &width, &height);
		ft_get_name(filename, "images/xpm/ghost/walk/left/ghost_left_walk_", i);
		if (open(filename, O_RDWR) == -1)
			file_not_found(app, filename);
		app->left_walk_frames[i++]
			= mlx_xpm_file_to_image(app->mlx, filename, &width, &height);
		free(filename);
	}
}

static void	load_jump_frames(t_ghost *app)
{
	int		width;
	int		height;
	int		i;
	char	*filename;

	i = 0;
	while (i < 8)
	{
		filename = malloc(sizeof(char) * 100);
		if (filename == NULL)
			return ;
		ft_get_name(filename, "images/xpm/ghost/jump/right/ghost_jump_up_", i);
		if (open(filename, O_RDWR) == -1)
			file_not_found(app, filename);
		app->right_jump_frames[i]
			= mlx_xpm_file_to_image(app->mlx, filename, &width, &height);
		ft_get_name(filename,
			"images/xpm/ghost/jump/left/ghost_left_jump_up_", i);
		if (open(filename, O_RDWR) == -1)
			file_not_found(app, filename);
		app->left_jump_frames[i++]
			= mlx_xpm_file_to_image(app->mlx, filename, &width, &height);
		free(filename);
	}
}

static void	load_death_frames(t_ghost *app)
{
	int		width;
	int		height;
	int		i;
	char	*filename;

	i = 0;
	while (i < 8)
	{
		filename = malloc(sizeof(char) * 100);
		if (filename == NULL)
			return ;
		ft_get_name(filename, "images/xpm/ghost/death/right/ghost_death_", i);
		if (open(filename, O_RDWR) == -1)
			file_not_found(app, filename);
		app->right_death_frames[i]
			= mlx_xpm_file_to_image(app->mlx,
				filename, &width, &height);
		ft_get_name(filename,
			"images/xpm/ghost/death/left/ghost_death_left_", i);
		if (open(filename, O_RDWR) == -1)
			file_not_found(app, filename);
		app->left_death_frames[i++]
			= mlx_xpm_file_to_image(app->mlx, filename, &width, &height);
		free(filename);
	}
}

static void	load_disappear_frames(t_ghost *app)
{
	int		width;
	int		height;
	int		i;
	char	*filename;

	i = 0;
	while (i < 8)
	{
		filename = malloc(sizeof(char) * 100);
		if (filename == NULL)
			return ;
		ft_get_name(filename,
			"images/xpm/ghost/disappear/right/ghsot_disappear_", i);
		if (open(filename, O_RDWR) == -1)
			file_not_found(app, filename);
		app->right_disappear_frames[i]
			= mlx_xpm_file_to_image(app->mlx, filename, &width, &height);
		ft_get_name(filename,
			"images/xpm/ghost/disappear/left/ghsot_disappear_left_", i);
		if (open(filename, O_RDWR) == -1)
			file_not_found(app, filename);
		app->left_disappear_frames[i++]
			= mlx_xpm_file_to_image(app->mlx, filename, &width, &height);
		free(filename);
	}
}

void	load_ghost_frames(t_ghost *app)
{
	load_walk_frames(app);
	load_jump_frames(app);
	load_death_frames(app);
	load_disappear_frames(app);
}

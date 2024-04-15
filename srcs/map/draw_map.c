/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:14:36 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/19 14:33:53 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	print_nbr_moves(t_ghost *app)
{
	char	*moves_str;
	char	*num;

	num = ft_itoa_2(app->number_moves);
	moves_str = (char *)malloc(sizeof(char) * 100);
	ft_strlcpy(moves_str, "Moves: ");
	ft_strlcat(moves_str, num);
	mlx_string_put(app->mlx, app->win, 10, 10, 0xFFFFFF, moves_str);
	free(num);
	free(moves_str);
}

static void	draw_enemies(t_ghost *app)
{
	int	e;

	e = 0;
	while (e < app->enemies_number)
	{
		draw_enemy(app, app->current_enemy_direction[e], e);
		e++;
	}
}

static void	draw_components(t_ghost *app, int i, int j)
{
	mlx_put_image_to_window(app->mlx,
		app->win, app->surface_image,
		j * app->wall_size, i * app->wall_size);
	if (app->map[i][j] == 1)
		mlx_put_image_to_window(app->mlx,
			app->win, app->obstacle_image,
			j * app->wall_size, i * app->wall_size);
	if (app->map[i][j] == 3)
		mlx_put_image_to_window(app->mlx,
			app->win, app->collectible_image,
			j * app->wall_size, i * app->wall_size);
	if (app->map[i][j] == -1)
	{
		if (app->collectible_count != 0)
			mlx_put_image_to_window(app->mlx,
				app->win, app->door_frames[0],
				j * app->wall_size, i * app->wall_size);
		else if (app->is_door_open[1])
			mlx_put_image_to_window(app->mlx,
				app->win, app->door_frames[4],
				j * app->wall_size, i * app->wall_size);
	}
}

void	draw_map(t_ghost *app)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(app->mlx, app->win);
	while (i < app->map_dimension[1])
	{
		j = 0;
		while (j < app->map_dimension[0])
		{
			draw_components(app, i, j);
			j++;
		}
		i++;
	}
	draw_ghost(app, app->current_move);
	draw_enemies(app);
	print_nbr_moves(app);
	mlx_do_sync(app->mlx);
}

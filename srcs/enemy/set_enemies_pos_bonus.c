/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_enemies_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:48:43 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	help_func(t_ghost *app, int vars[6])
{
	if (app->map[vars[1]][vars[0]] == 0)
		vars[2]++;
	else
		vars[2] = 0;
	if (vars[1] < app->map_dimension[1] - 1)
	{
		if (app->map[vars[1] + 1][vars[0]] == 0)
			vars[3]++;
		else
			vars[3] = 0;
	}
	if (vars[1] > app->map_dimension[1])
	{
		if (app->map[vars[1] - 1][vars[0]] == 0)
			vars[4]++;
		else
			vars[4] = 0;
	}
	if ((vars[2] == 3 && vars[3] >= 2) || (vars[2] == 3 && vars[4] >= 2))
	{
		app->enemie_x_y[vars[5]][0] = (vars[0] - 2) * 48 + 15;
		app->enemie_x_y[vars[5]][1] = vars[1] * 48 + 15;
		vars[5]++;
	}
}

void	set_enemies_pos(t_ghost *app)
{
	int	vars[6];

	vars[1] = 0;
	vars[2] = 0;
	vars[4] = 0;
	vars[5] = 0;
	while (vars[1] < app->map_dimension[1])
	{
		vars[0] = 0;
		vars[2] = 0;
		vars[3] = 0;
		vars[4] = 0;
		while (vars[0] < app->map_dimension[0])
		{
			help_func(app, vars);
			if (vars[5] == app->enemies_number)
				return ;
			vars[0]++;
		}
		vars[1]++;
	}
}

// void	set_enemies_pos(t_ghost *app)
// {
// 	int	y;
// 	int	x;
// 	int	k;
// 	int	f;
// 	int	t;
// 	int	n;

// 	y = 0;
// 	k = 0;
// 	n = 0;
// 	t = 0;
// 	while (y < app->map_dimension[1])
// 	{
// 		x = 0;
// 		k = 0;
// 		f = 0;
// 		t = 0;
// 		while (x < app->map_dimension[0])
// 		{
// 			if (app->map[y][x] == 0)
// 				k++;
// 			else
// 				k = 0;
// 			if (y < app->map_dimension[1] - 1)
// 			{
// 				if (app->map[y + 1][x] == 0)
// 					f++;
// 				else
// 					f = 0;
// 			}
// 			if (y > app->map_dimension[1])
// 			{
// 				if (app->map[y - 1][x] == 0)
// 					t++;
// 				else
// 					t = 0;
// 			}
// 			if ((k == 3 && f >= 2) || (k == 3 && t >= 2))
// 			{
// 				app->enemie_x_y[n][0] = (x - 2) * 48 + 15;
// 				app->enemie_x_y[n][1] = y * 48 + 15;
// 				n++;
// 			}
// 			if (n == app->enemies_number)
// 				return ;
// 			x++;
// 		}
// 		y++;
// 	}
// }

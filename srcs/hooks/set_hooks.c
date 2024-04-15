/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:56:09 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/19 15:29:59 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_hooks(t_ghost *app)
{
	mlx_hook(app->win, 2, 1, key_press, app);
	mlx_hook(app->win, 3, 1, key_release, app);
	mlx_hook(app->win, 17, 0, close_window, app);
	mlx_loop_hook(app->mlx, (void *)animate_enemy_loop, app);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:35:02 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:04:59 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	game_over(t_ghost *app, int e)
{
	animate_enemy_attack(7, app, e);
	animate_death(app);
	custom_delay(10000000);
	ft_printf("Game Over!\n");
	close_window(app);
}

void	enemy_change_direction(t_ghost *app, int e)
{
	if (app->current_enemy_direction[e] == 5)
		app->current_enemy_direction[e] = 6;
	else if (app->current_enemy_direction[e] == 6)
		app->current_enemy_direction[e] = 5;
}

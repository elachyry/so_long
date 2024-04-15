/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:34:05 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ghost_exit(t_ghost *app)
{
	animate_disappear(app);
	free_map(app->map, app->map_dimension[1]);
	custom_delay(1000000);
	ft_printf("You win!\n");
	close_window(app);
}

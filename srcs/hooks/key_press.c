/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:53:18 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	key_press_right(t_ghost *app)
{
	app->is_long_press = 1;
	app->current_direction = 0;
	app->current_move = 0;
	animate_and_move_ghost(app);
}

static void	key_press_left(t_ghost *app)
{
	app->is_long_press = 1;
	app->current_direction = 1;
	app->current_move = 1;
	animate_and_move_ghost(app);
}

static void	key_press_top(t_ghost *app)
{
	app->is_long_press = 1;
	app->current_move = 2;
	animate_and_move_ghost(app);
}

static void	key_press_bottom(t_ghost *app)
{
	app->is_long_press = 1;
	app->current_move = 3;
	animate_and_move_ghost(app);
}

int	key_press(int keycode, t_ghost *app)
{
	if (keycode == 124)
		key_press_right(app);
	else if (keycode == 123)
		key_press_left(app);
	else if (keycode == 126)
		key_press_top(app);
	else if (keycode == 125)
		key_press_bottom(app);
	else if (keycode == 53)
		close_window(app);
	app->is_long_press = 0;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_exceptions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:03:09 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/20 11:08:56 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	file_not_found(t_ghost *app, char *filename)
{
	free_map(app->map, app->map_dimension[1]);
	ft_printf("The file %s not found!\n", filename);
	exit(1);
}

void	map_file_empty(void)
{
	ft_printf("The map file is empty!\n");
	exit(1);
}

void	map_extention_wrong(void)
{
	ft_printf("The map extention is wrong!\n");
	exit(1);
}

void	map_file_not_exist(void)
{
	ft_printf("The map file does not exist!\n");
	exit(1);
}

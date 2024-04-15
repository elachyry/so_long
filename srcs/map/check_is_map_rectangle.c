/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_map_rectangle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:32:24 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/20 10:04:37 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool	check_is_map_rectangle(int height, char *path)
{
	int		i;
	int		fd;
	int		len;
	char	*str;
	bool	result;

	fd = open(path, O_RDWR);
	str = get_next_line(fd);
	len = ft_strlen_2(str);
	i = 0;
	result = true;
	while (str != NULL)
	{
		if (len != ft_strlen_2(str) && i < (height - 1))
			result = false;
		if ((len - 1) != ft_strlen_2(str) && i++ == (height - 1))
			result = false;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (result);
}

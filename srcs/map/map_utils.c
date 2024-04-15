/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:40:03 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/20 10:22:52 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	get_map_height(char *path)
{
	int		i;
	int		fd;
	char	*str;

	fd = open(path, O_RDWR);
	str = get_next_line(fd);
	i = 0;
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

void	check_map_extention(char *filename)
{
	int		filename_len;
	char	*file_extention;
	char	*file_name_start;

	filename_len = ft_strlen(filename);
	if (filename_len < 3 || filename[0] == '.')
		map_extention_wrong();
	file_name_start = ft_strchr(filename, '/');
	if (file_name_start != NULL)
	{
		if (*(file_name_start + 1) == '.')
			map_extention_wrong();
	}
	file_extention = filename + (filename_len - 4);
	if (ft_strncmp(file_extention, ".ber", filename_len) != 0)
		map_extention_wrong();
}

void	free_map(int **map, int lengh)
{
	int	i;

	i = 0;
	while (i < lengh)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

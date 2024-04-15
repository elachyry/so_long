/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:41:20 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/19 19:09:45 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	upload_components(t_ghost *app, char *str, int i)
{
	int	j;

	j = 0;
	while (j < app->map_dimension[0])
	{
		if (str[j] == '1')
			app->map[i][j] = 1;
		else if (str[j] == '0')
			app->map[i][j] = 0;
		else if (str[j] == 'P')
			app->map[i][j] = 2;
		else if (str[j] == 'C')
			app->map[i][j] = 3;
		else if (str[j] == 'E')
			app->map[i][j] = -1;
		else if (str[j] != 10)
		{
			app->map_dimension[1] = i + 1;
			components_exception(app);
		}
		j++;
	}
}

void	upload_map(t_ghost *app, char *path)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(path, O_RDWR);
	str = get_next_line(fd);
	if (str == NULL)
		map_file_empty();
	app->map_dimension[0] = ft_strlen_2(str) - 1;
	i = 0;
	while (i < app->map_dimension[1] && str != NULL)
	{
		app->map[i] = (int *)malloc(sizeof(int) * (app->map_dimension[0]));
		upload_components(app, str, i);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	free(str);
	close(fd);
}

// ft_printf("test\n");
// for (int i = 0; i < app->map_dimension[1]; i++) {
// 	for (int j = 0; j < app->map_dimension[0]; j++) {
// 		ft_printf("%d", app->map[i][j]);
// 	}
// 	ft_printf("\n");
// }
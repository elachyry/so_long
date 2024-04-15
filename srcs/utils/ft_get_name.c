/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:38:57 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 12:31:15 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*ft_get_name(char *result, char *path, int number)
{
	char	*index;

	index = ft_itoa_2(number);
	ft_strlcpy(result, path);
	ft_strlcat(result, index);
	ft_strlcat(result, ".xpm");
	free(index);
	return (result);
}

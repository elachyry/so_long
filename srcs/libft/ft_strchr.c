/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:50:18 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 20:56:37 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	len;

	len = ft_strlen(str);
	if ((char)c == '\0')
		return ((void *)str + len);
	while (len > 0)
	{
		len--;
		if ((char)str[len] == (char)c)
			return ((void *)str + len);
	}
	return (NULL);
}

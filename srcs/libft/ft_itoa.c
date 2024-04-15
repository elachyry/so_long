/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:27:15 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 13:51:24 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	ft_diglen(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count = 1;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*help_func(int n)
{
	if (n == -2147483648)
		return (ft_strdup_2("-2147483648"));
	else
		return (ft_strdup_2("0"));
}

char	*ft_itoa_2(int n)
{
	char	*result;
	int		count;

	if (n == -2147483648 || n == 0)
		return (help_func(n));
	count = ft_diglen(n);
	result = (char *)malloc(sizeof(char) * (count + 1));
	if (result == NULL)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		result[0] = '-';
	}
	result[count] = '\0';
	while (n > 0)
	{
		count--;
		result[count] = (n % 10) + 48;
		n /= 10;
	}
	return (result);
}

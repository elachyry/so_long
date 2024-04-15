/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:42:13 by melachyr          #+#    #+#             */
/*   Updated: 2023/12/22 17:18:02 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_hexlen(unsigned int number)
{
	int	count;

	count = 0;
	while (number != 0)
	{
		number /= 16;
		count++;
	}
	return (count);
}

int	ft_puthex(unsigned int number, const char fs)
{
	char	c;

	if (number >= 10)
	{
		if (fs == 'x')
			c = (number - 10) + 'a';
		else
			c = (number - 10) + 'A';
	}
	else
		c = number + '0';
	if (number >= 16)
	{
		if (ft_puthex(number / 16, fs) == -1)
			return (-1);
		if (ft_puthex(number % 16, fs) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar(c) == -1)
			return (-1);
	}
	return (ft_hexlen(number));
}

int	ft_printf_hex(unsigned int number, const char fs)
{
	if (number > 0)
		return (ft_puthex(number, fs));
	else
		return (ft_putchar('0'));
}

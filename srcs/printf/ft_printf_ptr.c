/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:27:05 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 10:25:17 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_ptrlen(size_t ptr)
{
	int	count;

	count = 0;
	while (ptr > 0)
	{
		ptr /= 16;
		count++;
	}
	return (count);
}

int	ft_putptr(size_t ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr >= 10)
			ft_putchar((ptr - 10) + 'a');
		else
			ft_putchar(ptr + '0');
	}
	return (ft_ptrlen(ptr));
}

int	ft_printf_ptr(size_t ptr)
{
	int	printedlen;
	int	result;

	printedlen = ft_putstr("0x");
	if (printedlen == -1)
		return (-1);
	if (ptr == 0)
	{
		result = ft_putchar('0');
		if (result == (-1))
			return (-1);
		printedlen += result;
	}
	else
		printedlen += ft_putptr(ptr);
	return (printedlen);
}

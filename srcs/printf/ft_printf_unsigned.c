/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:23:04 by melachyr          #+#    #+#             */
/*   Updated: 2023/12/23 09:33:03 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_udiglen(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_utoa(unsigned int n)
{
	char	*result;
	int		count;

	if (n == 0)
		return (ft_strdup("0"));
	count = ft_udiglen(n);
	result = (char *)malloc(sizeof(char) * (count + 1));
	if (result == NULL)
		return (NULL);
	result[count] = '\0';
	while (n > 0)
	{
		count--;
		result[count] = (n % 10) + 48;
		n /= 10;
	}
	return (result);
}

int	ft_printf_unsigned(unsigned int number)
{
	int		printedlen;
	char	*result;

	result = ft_utoa(number);
	if (result == NULL)
		return (-1);
	printedlen = ft_putstr(result);
	free(result);
	return (printedlen);
}

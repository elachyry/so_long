/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:16:38 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:50:23 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = (char)s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_diglen(int n)
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

char	*ft_itoa(int n)
{
	char	*result;
	int		count;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
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

int	ft_printf_int(int number)
{
	int		printedlen;
	char	*result;

	result = ft_itoa(number);
	if (result == NULL)
		return (-1);
	printedlen = ft_putstr(result);
	free(result);
	return (printedlen);
}
